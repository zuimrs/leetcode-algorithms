#!/usr/bin/python
# -*- coding: UTF-8 -*-
# FILE: manage.py
# AUTHOR: zuimrs

import argparse

from utils import managerAPI

def init_subparsers(parent):
    """
    TODO:指定命令和函数入口
    """
    subparsers = parent.add_subparsers(title='commands')

    # clean
    # 清除所有本地leetcode文件
    parser_clean = subparsers.add_parser(
        'clean',
        help = 'Clean all local files.'
    )
    parser_clean.set_defaults(func=managerAPI.clean)


    # config
    # 配置用户信息
    parser_config = subparsers.add_parser(
        'config',
        help = 'Reset configuration'
    )
    parser_config.set_defaults(func=managerAPI.config)

    # sync
    # 爬取leetcode的所有问题，并创建空文件夹
    # 如果用户配置了leetcode密码，将leetcode解题文件更新到本地
    parser_sync = subparsers.add_parser(
        'sync',
        help = 'Sync all algorithm problem from leetcode.'
    )
    parser_sync.set_defaults(func=managerAPI.sync)

    # update
    # 更新README.md
    parser_update = subparsers.add_parser(
    'update',
    help = 'Update README.file.'
    )
    parser_update.set_defaults(func=managerAPI.update)

'''

    # watchdog
    # 定时拉取leetcode并更新到github
    parser_update = subparsers.add_parser(
        'watchdog',
        help = 'Sync,update and push to github periodly.'
    )
    parser_update.set_defaults(func=watchdog.func)
'''
def parse_args():
    parser = argparse.ArgumentParser()

    parser.add_argument(
        '-v', '--version',
        action='version',
        version='version = 0.0.1',
    )

    init_subparsers(parser)

    return parser.parse_args()


def main():
    """
    TODO:处理命令行参数
    """

    # 获取参数
    args = parse_args()
    # 执行指令
    args.func(args)


if __name__ == '__main__':
    """
    MAIN:程序入口
    """
    main()
