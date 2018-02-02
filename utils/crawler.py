#!/usr/bin/python
# -*- coding: utf-8 -*-
# FILE: crawler.py
# AUTHOR: zuimrs
"""
"""
import datetime
import json
import multiprocessing
import os
import re
import requests
import sys

import tools

from .common import LANG_SETTING
from .common import LOCAL_FOLDER_PATH
from .common import PROCESS_COUNT_LIMIT


class Crawler:
    def __init__(self):
        from .config import Config
        self.__solved_question_on_leetcode = []

        # request会话
        self.__session = requests.Session()

        # 读取login_info
        self.__config = Config()
        self.__login_info = self.__config.leetcode_login_info
        self.__login_info['csrfmiddlewaretoken'] = self.__get_csrf_token()

        # 登录
        self.__login_leetcode()

        # 获取问题
        self.__get_leetcode_question()

        # 保存question列表到json
        self.__save_json()

        # 创建文件夹(支持无登录创建)
        self.__create_folders()

        # 检测登录是否成功
        firstflag = flag = self.__check_login_success()
        while not flag:
            # 登录失败
            self.__handle_login_failed()
            flag = self.__check_login_success()

        # 再次保存question字典到json
        if not firstflag: #曾经登录失败过，需要更新json文件
            self.__save_json()

        # 同步leetcode代码到本地
        self.__sync_leetcode()


    @property
    def global_ranking(self):

        return "28698 / 38404"

    def __login_leetcode(self):
        """
        模拟登录leetcode，更新会话
        """
        tools.handle_requests(self.__session,'https://leetcode.com/accounts/login/',
            'POST', data = self.__login_info)


    def __get_leetcode_question(self):
        """
        利用get请求获取leetcode的question字典
        """
        # Get
        question_info = tools.handle_requests(self.__session,'https://leetcode.com/api/problems/algorithms/').text
        self.__question_dict = json.loads(question_info)



    def __save_json(self):
        """
        将question字典保存保存到json中
        """
        from .common import LEETCODE_JSON_PATH
        tools.save_into_json(LEETCODE_JSON_PATH,self.__question_dict)
        print "\n-------Download leetcode questions completed-------\n"


    def __sync_leetcode(self):
        """
        同步leetcode解题代码到本地
        """
        question_list = self.__question_dict['stat_status_pairs']
        for question in question_list:
            if question["status"] == "ac":
                self.__solved_question_on_leetcode.append({
                    'id':question['stat']['frontend_question_id'],
                    'title':question['stat']['question__title'],
                    'title_slug':question['stat']['question__title_slug'],})

        self.__get_solution_from_leetcode()


    def __get_solution_from_leetcode(self):
        """
        从leetcode下载solution代码
        """
        # 多进程
        manager = multiprocessing.Manager()
        cur = manager.Value('i',0)
        count_old = manager.Value('count_old',0)
        count_new = manager.Value('count_new',0)

        lock = manager.Lock()

        process_id = 0

        searcher = re.compile(r"submissionCode:\s*'(.*)',\s*editCodeUrl:\s*'")

        print "\n-------Create {0} process to fetch solution code-------\n".format(PROCESS_COUNT_LIMIT)

        pool = multiprocessing.Pool(PROCESS_COUNT_LIMIT)

        import time
        import random

        for process_id in range(PROCESS_COUNT_LIMIT):
            pool.apply_async(worker,(
                self.__login_info['login'],#user_account
                self.__solved_question_on_leetcode,
                self.__session,
                cur,
                count_old,
                count_new,
                lock,
                process_id,
                searcher,
            ))
        # print "worker done"
        pool.close()
        pool.join()
        print "\n\tTotal:{0}\tOld:{1}\tNew:{2}".format(
                str(count_old.value + count_new.value),
                str(count_old.value),
                str(count_new.value)
            )
        print "\n-------Fetch solution code completed-------\n".format(PROCESS_COUNT_LIMIT)

    @staticmethod
    def get_latest_answer(question_title_slug,session,searcher):
        """
        获取question的最新的ac代码
        """

        leetcode_url = 'https://leetcode.com/api/submissions/{0}/?format=json'.format(question_title_slug)
        solved_info = tools.handle_requests(session,leetcode_url).text
        solved_dict = json.loads(solved_info)

        url = ''

        # 存储solution信息的列表
        result_list = []
        # 使用的语言列表
        lang_list = []

        for item in solved_dict['submissions_dump']:
            if item['status_display'] == 'Accepted' and \
                (LANG_SETTING is None or item['lang'] in LANG_SETTING.keys()):
                if item['lang'] in lang_list:
                    # 同种语言只保存最新提交
                    continue
                else:
                    lang_list.append(item['lang'])
                    ret = {}
                    ret['file_name'] = '{0}.{1}'.format(question_title_slug,
                        LANG_SETTING[item['lang']]['extension_name']) # 编程语言扩展名
                    ret['url'] = question_title_slug.replace('-','%20')
                    ret['lang'] = item['lang']
                    ret['runtime'] = item['runtime']

                    # 代码对应url
                    leetcode_url = 'https://leetcode.com{0}'.format(item['url'])
                    # get方法获取代码内容
                    text = tools.handle_requests(session,leetcode_url).text
                    # 正则匹配
                    ret['code'] = searcher.search(text).group(1).encode('utf-8').decode('unicode_escape')

                    # 添加到结果列表
                    result_list.append(ret)

        return result_list



    def __check_login_success(self):
        """
        返回leetcode登录是否成功
        """
        return self.__login_info['login'] == self.__question_dict['user_name']


    def __handle_login_failed(self):
        """
        处理leetcode登录失败的逻辑
        """
        print "\nWARNING: Sync LeetCode failed,please check your password."

        # 请求重新输入密码
        password = raw_input("\nPlease input LeetCode password(press Y/y to exit):")

        if password == 'Y' or password =='y':
            exit(0)
        else:
            # 更新密码
            self.__login_info['password'] = password
            # 更新到config文件
            self.__config.reset_leetcode_config(self.__login_info)
            # 重登录
            self.__login_leetcode()
            # 获取问题
            self.__get_leetcode_question()



    def __get_csrf_token(self):
        # 登录
        result = tools.handle_requests(self.__session, 'https://leetcode.com/accounts/login/').text
        # get csrf value
        return re.search(r"csrfmiddlewaretoken'\s*value='(.*)'", result).group(1).encode('ascii')

        # 如果密码为空
        if self.__login_info['password'] is '':
            print "\nLeetCode account: {}\n".format(self.__login_info['login'])
            self.__login_info['password'] = raw_input("Please input LeetCode password:")
            # 更新config文件
            self.__config.reset_leetcode_config(self.__login_info)


    def __create_folders(self):
        """
        根据leetcode问题列表创建对应文件夹
        """

        if not os.path.exists(LOCAL_FOLDER_PATH):
            print(LOCAL_FOLDER_PATH + 'is not exits, create it now....')
            try:
                os.mkdir(LOCAL_FOLDER_PATH)
            except:
                print "ERROR: Create question folder {0} failed.".format(LOCAL_FOLDER_PATH)
                exit(0)

        # 获取question列表
        question_list = self.__question_dict['stat_status_pairs']

        for question in  question_list:

            question_id = str(question['stat']['frontend_question_id']).zfill(3)

            question_title = question['stat']['question__title']


            question_folder_name = '{0}. {1}'.format(question_id,question_title)

            question_folder_path = os.path.join(LOCAL_FOLDER_PATH,question_folder_name)

            if not os.path.exists(question_folder_path):
                # 如果文件夹不存在
                print(question_folder_path + 'is not exits, create it now....')
                try:
                    os.mkdir(question_folder_path)
                except:
                    print "ERROR: Create question folder {0} failed.".format(question_folder_path)
                    exit(0)
        print "\n-------Create new question folders completed-------\n"


def worker(user_account,solved_question_list,session,cur,count_old,count_new,lock,process_id,searcher):
    import time
    import random

    while True:
        # 进程私有变量
        index = cur.value * PROCESS_COUNT_LIMIT + process_id
        # print '\n{}'.format(str(index))
        if index >= len(solved_question_list):
            break
        solved_question = solved_question_list[index]

        question_id = str(solved_question['id']).zfill(3)
        question_title = solved_question['title']
        question_title_slug = solved_question['title_slug']

        folder_name = '{0}. {1}/'.format(question_id,question_title)
        folder_path = os.path.join(LOCAL_FOLDER_PATH,folder_name)

        with lock:
            time.sleep(random.random())
            ac_list = Crawler.get_latest_answer(question_title_slug,session,searcher)

        for item in ac_list:
            # print os.path.join(folder_path,item['file_name'])
            if tools.judge_file_exists(folder_path,item['file_name']) == True:
                print "  Process {0}: File {1} already exists.".format(
                    process_id,os.path.join(folder_path,item['file_name']))
                with lock:
                    count_old.value += 1
                continue
            else:
                flag = save_solution_code(folder_path,item['file_name'],item,user_account)
                if flag:
                    print "  Process {0}: Fetch {1} of question {2}.".format(
                        process_id,item['file_name'],question_id)
                    with lock:
                        count_new.value += 1
        with lock:
            if process_id == 0:
                cur.value += 1
        # print "ok"


def save_solution_code(folder_path,file_name,content,user_account):
    """
    将solution代码写入文件
    """
    #  文件路径
    file_path = os.path.join(folder_path,file_name)

    # 文件内容
    content_text = \
    ('{0}\r\n'
    '{1}File: {3}'
    '{1}https://leetcode.com/problems/{4}/\r\n'
    '{1}By {5}\r\n'
    '{1}Runtime:  {6}\r\n'
    '{1}Language: {7}\r\n'
    '{2}\r\n'
    '\r\n'
    '{8}').format(
        LANG_SETTING[content['lang']]['prefix'],#{0}
        LANG_SETTING[content['lang']]['middle'],#{1}
        LANG_SETTING[content['lang']]['suffix'],#{2}
        content['file_name'],#{3}
        content['url'],#{4}
        user_account,#{5}
        content['runtime'],#{6}
        content['lang'],#{7}
        content['code'],#{8}
    )
    return tools.write_into_file(filepath=file_path,content=content_text)



def test():
    crawler = Crawler()

if __name__ == "__main__":
    test()
