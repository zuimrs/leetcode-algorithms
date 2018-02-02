#!/usr/bin/python
# -*- coding: utf-8 -*-
# FILE: managerAPI.py
# AUTHOR: zuimrs


def clean(args):
    import os
    import shutil
    try:
        shutil.rmtree('leetcode-problems')
        os.mkdir('leetcode-problems')
    except:
        print "ERROR: Clean folder failed."
    return 'ok'


def config(args):
    """
    命令 Python manage.py config
    manage.py调用的接口函数
    """
    from .config import Config
    config = Config()
    config.set_config()


def sync(argv):
    """
    命令 Python manage.py download
    manage.py调用的接口函数
    """
    from .crawler import Crawler
    crawler = Crawler()
    # crawler.fetch_questions_from_leetcode()
    # crawler.create_folders()

def update(argv):
    """
    命令 Python manage.py update
    manage.py调用的接口函数
    """
    from .readme import Readme
    readme = Readme()
    readme.create_leetcode_readme()
