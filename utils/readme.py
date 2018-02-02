#!/usr/bin/env python
# -*- coding: utf-8 -*-
# FILE: update.py
# AUTHOR: zuimrs
import os
import time

import tools

from .common import LANG_SETTING
from .common import MD_TEMPLATE_PATH
from .config import Config
from .crawler import Crawler
from .leetcode import QuestionTable,SolutionTable

class Readme:
    """
    生成Readme.md
    """
    def __init__(self):
        config = Config()
        self.question_table = QuestionTable()
        self.solution_table = SolutionTable()
        self.msg = tools.read_from_file(MD_TEMPLATE_PATH)
        assert isinstance(self.msg,str)

        leetcode_account = config.leetcode_account
        github_account = config.github_account

        ranking = '1/1'

        total_solved_num = self.solution_table.total_solved_num
        locked_num = self.question_table.locked_num
        total_num = self.question_table.total_question_num

        hard = self.solution_table.get_solved_num_by_difficulty('Hard')
        medium = self.solution_table.get_solved_num_by_difficulty('Medium')
        easy = self.solution_table.get_solved_num_by_difficulty('Easy')

        lang = str(LANG_SETTING.keys())

        t = time.strftime("%Y-%m-%d %H:%M:%S", time.localtime())

        png_url = "https://github.com/{}/leetcode-algorithms/raw/master/config/site-logo.png".format(github_account)

        self.msg = self.msg.format(png_url,leetcode_account,ranking,total_solved_num,total_num,locked_num,
                        hard,medium,easy,lang,t)

    def create_leetcode_readme(self):
        """
        create REAdME.md
        :return:
        """
        file_path = './README.md'

        # makrdown header
        with open(file_path, 'w') as f:
            f.write(self.msg)
            f.write('\n----------------\n')

        # markdown body
        with open(file_path, 'a') as f:
            f.write('### My leetcode solutions\n')
            s = '| ID | Title | Difficulty |'
            for lang in LANG_SETTING.keys():
                s += ' {0} |'.format(lang)
            s+= '\n'
            f.write(s)

            f.write('|:---:' * (3+len(LANG_SETTING.keys())) + '|\n')

            solution_url_dict = self.solution_table.get_solution_url_dict()
            assert isinstance(solution_url_dict,dict)

            for item in self.question_table.get_question_list():
                assert isinstance(item,QuestionTable.Question)
                data = {
                    'id': item.id_,
                    'title': '[{0}]({1}) {2}'.format(item.title, item.leetcode_url, ':lock:' if item.is_locked  else ''),
                    'difficulty': item.difficulty,
                    # 'js': item.javascript if item.javascript else 'To Do',
                    # 'python': item.python if item.python else 'To Do',
                    # 'c++': item.c_plus_plus if item.c_plus_plus else 'To Do',
                    # 'java': item.java if item.java else 'To Do'
                }
                for lang in LANG_SETTING.keys():
                    if solution_url_dict.has_key(item.id_) and solution_url_dict[item.id_][lang]:
                        # 例如：https://github.com/zuimrs/leetcode-algorithms/blob/demo/leetcode-problems/007.%20Reverse%20Integer/reverse-integer.cpp
                        data[lang] = '[:white_check_mark:{0}]({1})'.format(lang,solution_url_dict[item.id_][lang])
                    else:
                        data[lang] = 'TODO'

                s = '|{id}|{title}|{difficulty}|'
                for lang in LANG_SETTING.keys():
                    s += ''.join(['{',lang,'}|'])
                s += '\n'
                line = s.format(**data)
                f.write(line)


            print('-------README.md was updated-------')

def test():
    readme = Readme()
    readme.create_leetcode_readme()

if __name__ == '__main__':
    test()
