#!/usr/bin/python
# -*- coding: utf-8 -*-
# FILE: leetcode.py
# AUTHOR: zuimrs
"""

"""
import os

import tools

from .common import DIFFICULTYS
from .common import LANG_SETTING



class QuestionTable:
    class Question:
        """
        保存question的实例。
        属性：
        'id_':leetcode question编号
        'title':leetcode question标题
        'leetcode_url': question对应leetcode链接
        'is_locked'：question是否锁定
        'difficulty':难度'Easy', 'Medium', 'Hard'
        """
        def __init__(self,id_,title,leetcode_url,is_locked,difficulty):
            self.id_ = id_
            self.title = title
            self.leetcode_url = leetcode_url
            self.is_locked = is_locked
            self.difficulty = difficulty
    """
    保存所有question的数据表。
    """
    def __init__(self):
        # 保存id和question实例对应的字典
        self.__question_dict = {}
        self.__question_list = []
        self.locked_num = 0
        self.__load_json()

    @property
    def total_question_num(self):
        """
        返回leetcode题目总数
        """
        return len(self.__question_dict)


    def get_difficulty_dict(self):
        """
        获取question对应难度的字典
        """
        key = self.__question_dict.keys()
        value =[item.difficulty for item in self.__question_dict.values()]
        return dict(zip(key,value))

    def get_question_list(self):
        """
        获取question列表
        """
        return self.__question_list


    def __load_json(self):
        """
        从json加载
        """
        from .common import LEETCODE_JSON_PATH
        # 读取json文件
        question_dict = tools.load_from_json(LEETCODE_JSON_PATH)
        question_list = question_dict['stat_status_pairs']
        for i in range(len(question_list) - 1, -1, -1):
            question = question_list[i]
            # TODO: 可扩展其他信息
            id_ = str(question['stat']['frontend_question_id']).zfill(3)
            title = question['stat']['question__title']
            leetcode_url = 'https://leetcode.com/problems/{0}/description/'.format(question['stat']['question__title_slug'])
            is_locked = question['paid_only']
            difficulty = DIFFICULTYS[question['difficulty']['level'] - 1]

            # 实例化question
            question_obj = self.Question(id_= id_,title=title,leetcode_url=leetcode_url,is_locked=is_locked,difficulty=difficulty)

            # 将question object保存到question_dict中
            self.__question_dict[id_] = question_obj
            self.__question_list.append(question_obj)
            # 更新locked问题数
            if is_locked: self.locked_num += 1



class SolutionTable:
    """
    保存已经AC的question对应的解答信息，包括代码文件的github链接，解题数等
    """
    def __init__(self):
        # 获取github_path_url
        self.__github_path_url = self.__get_url_from_config()
        # solved 字典，每种语言对应AC题目数
        self.__solved_num = dict(zip(DIFFICULTYS,[0 for i in range(len(DIFFICULTYS))])) #{'Easy':0,'Medium':0, 'Hard':0}
        self.__solved_num_by_lang = dict(zip(LANG_SETTING.keys(),
            [dict(zip(DIFFICULTYS,[0 for i in range(len(DIFFICULTYS))])) for i in range(len(LANG_SETTING.keys()))]))
        # solution_url字典，题目对应代码的链接
        self.__solution_url = {}
        q_table = QuestionTable()
        self.__diffcult_dict = q_table.get_difficulty_dict()

        # update
        self.__update_solution_table()


    @property
    def total_solved_num(self):
        return len(self.__solution_url)


    def __get_url_from_config(self):
        from .config import Config
        config = Config()
        return config.github_url


    def __init_url_dict(self,key):
        url_dict = dict(zip(LANG_SETTING.keys(),[None for i in range(len(LANG_SETTING.keys()))]))
        self.__solution_url[key] = url_dict


    def get_solved_num_by_difficulty(self,difficulty):
        return self.__solved_num[difficulty]


    def get_solution_url_dict(self):
        return self.__solution_url


    def __update_solution_table(self):
        """
        遍历文件夹，获取不同语言已ac的问题列表
        """
        from .common import LOCAL_FOLDER_PATH
        print "\n-------Begin to update solution table-------\n"
        if not os.path.exists(LOCAL_FOLDER_PATH):
            print(LOCAL_FOLDER_PATH + 'is not exits, create it now....')
            try:
                os.mkdir(LOCAL_FOLDER_PATH)
            except:
                print "ERROR: Create question folder {0} failed.".format(LOCAL_FOLDER_PATH)
                raise IOError
        folders = tools.get_all_folders(LOCAL_FOLDER_PATH)
        for folder in folders:

            path = os.path.join(LOCAL_FOLDER_PATH,folder)
            # 获取question文件夹下的所有文件
            files = tools.get_all_files(path)

            # 若不存在代码文件
            if not files: continue

            # else
            q_index = folder[:3]
            self.__init_url_dict(q_index)
            difficulty = self.__diffcult_dict[q_index]
            self.__solved_num[difficulty] += 1

            for item in files:
                # 判断编程语言
                lang = tools.judge_lang(item)

                # 若文件不合法
                if not lang:
                    print "  Unknown file: {0} of question:{1}".format(item,q_index)
                    continue

                # 文件合法
                # 代码文件本地路径
                item_url = os.path.join(folder.replace(' ', "%20"), item)
                # 更新AC题目数量
                self.__solved_num_by_lang[lang][difficulty] += 1
                # 保存url
                self.__solution_url[q_index][lang] = os.path.join(self.__github_path_url, item_url)
                print "  FOUND {0} solution of question:{1};".format(lang,q_index)

        print "\n\n  {}".format(str(self.__solved_num))
        if self.total_solved_num == 0 : # 解题数为0
            print "\n  No solutions,Keep Coding!\n"
        else: # 解题数大于0
            print "\n  There are {} AC questions,Keep Coding!\n".format(self.total_solved_num)

        print "\n-------Update solution table completed-------\n"

def test():
    pass

if __name__=='__main__':
    test()
