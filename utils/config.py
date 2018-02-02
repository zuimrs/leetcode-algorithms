#!/usr/bin/python
# -*- coding: utf-8 -*-
# FILE: config.py
# AUTHOR: zuimrs
"""
config字典：

    config = {
        'github':{'account':None,'password':None,'repository':None,'path_url':None},
        'leetcode':{'login':None,'password':None}
    }

注意：
1. 密码明文保存在config.ini中，切勿将.gitignore中的”config.ini”删除。
2. github账号为必填项
3. leetcode账号密码用于爬取已经AC的题
4. github密码如果不填，需要手动push到远程仓库
"""

import ConfigParser

from .common import CONFIG_FILE_PATH
from .common import LOCAL_FOLDER_PATH

class Config:
    class GithubConfig:
        """
        保存github配置
        属性：
        account：github账号，
        password：github密码（非必填)，
        repository：该项目的仓库名，
        path_url:该项目”leetcode-problems”文件夹在github上的url
        """
        def __init__(self,github_account = None,github_password = None):
            if github_account is None and github_password is None:
                self.account = raw_input("github_account:")
                self.password = raw_input("github_password(Not Required):")
            else:
                self.account = github_account
                self.password = github_password
            # github上托管的leetcode文件夹
            self.path_url = ''.join(['https://github.com/',self.account, '/leetcode-algorithms/blob/demo/{}/'.format(LOCAL_FOLDER_PATH.split('/')[1]),])
            # fork的本项目地址
            if not self.password or self.password != '':
                self.repository = ''.join(['https://github.com/',self.account,'/leetcode-algorithms.git',])
            else:
                self.repository = ''.join(['https://',self.account,':',self.password,'@github.com/',self.account,'/leetcode-algorithms.git',])


        def dict_from_class(self):
            return self.__dict__

        def check_property(self):
            if not self.account:
                print "\n\nERROR: github_account cannot be empty.\n\n\nRESET {}:\n".format(CONFIG_FILE_PATH)
                return False
            return True

    class LeetcodeConfig:
        """
        保存leetcode配置
        属性：
        login：leetcode账号，
        password：leetcode密码（非必填)，
        """
        def __init__(self,leetcode_login = None,leetcode_password = None):
            if leetcode_login is None and leetcode_password is None:
                self.login = raw_input("leetcode_account:")
                self.password = raw_input("leetcode_password(Not Required):")
            else :
                self.login = leetcode_login
                self.password = leetcode_password

        def dict_from_class(self):
            return self.__dict__

        def check_property(self):
            if not self.login:
                print "\nERROR: Leetcode_account cannot be empty.\n\n\nRESET {}:\n".format(CONFIG_FILE_PATH)
                return False
            return True
    """
    TODO: 添加定时推送等配置信息
    """

    def __init__(self):
        self.__github_config = None
        self.__leetcode_config = None
        # 读取config.ini
        success_flag = self.__load_config()

        if not success_flag or not self.__check_property():
            # Load失败或内容不合法
            self.__input_config_from_keyboard()
        # 保存到config.ini
        self.__save_config()

    def set_config(self):
        self.__input_config_from_keyboard()
        self.__save_config()

    @property
    def github_url(self):
        return self.__github_config.path_url

    @property
    def leetcode_account(self):
        return self.__leetcode_config.login

    @property
    def leetcode_login_info(self):
        return self.__leetcode_config.dict_from_class()

    @property
    def github_account(self):
        return self.__github_config.account

    def __check_property(self):
        return self.__github_config.check_property() and self.__leetcode_config.check_property()

    def __input_config_from_keyboard(self):
        flag = False
        while not flag:
            self.__github_config = self.GithubConfig()
            # 再次检查合法性
            flag = self.__github_config.check_property()

        flag = False
        while not flag:
            self.__leetcode_config = self.LeetcodeConfig()
            # 再次检查合法性
            flag = self.__leetcode_config.check_property()


    def __load_config(self):
        """
        从config.ini加载配置信息
        """
        try:
            conf_parser = ConfigParser.ConfigParser()
            # 用config对象读取配置文件
            conf_parser.read(CONFIG_FILE_PATH)
            # 读文件
            leetcode_config_dict = conf_parser._sections['leetcode']
            github_config_dict = conf_parser._sections['github']

            self.__leetcode_config = self.LeetcodeConfig(leetcode_login=leetcode_config_dict['login'],
                leetcode_password=leetcode_config_dict['password'])

            self.__github_config = self.GithubConfig(github_account=github_config_dict['account'],
                github_password=github_config_dict['password'])

            return True
        except :
            # 读取失败
            print "\nWARNING: Load {0} failed,need to update:\n\n\nRESET {0}:\n".format(CONFIG_FILE_PATH)
            return False

    def reset_leetcode_config(self,leetcode_config_dict):
        """
        更新leetcode配置并保存
        """
        self.__leetcode_config = self.LeetcodeConfig(leetcode_login=leetcode_config_dict['login'],
            leetcode_password=leetcode_config_dict['password'])
        self.__save_config()



    def __save_config(self):
        """
        将用户输入保存到config.ini配置文件
        """
        conf_parser = ConfigParser.ConfigParser()
        #更新指定section，option的值
        conf_parser._sections['github'] = self.__github_config.dict_from_class()
        conf_parser._sections['leetcode'] = self.__leetcode_config.dict_from_class()

        try:
            #写回配置文件
            conf_parser.write(open(CONFIG_FILE_PATH, "w"))
        except :
            print "\nError:Write {} failed.".format(CONFIG_FILE_PATH)




def test():
    """
    测试函数
    """
    config = Config()

if __name__=='__main__':
    # Test
    test()
