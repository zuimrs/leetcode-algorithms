#!/usr/bin/python
# -*- coding: utf-8 -*-
# FILE: common.py
# AUTHOR: zuimrs
"""
"""

PROXIES = {
#    "https": "http://127.0.0.1:1080"
}

HEADERS = {
    'Referer': "https://leetcode.com",
    'Content-Type': 'application/x-www-form-urlencoded',
    'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_10_3) '
                  'AppleWebKit/537.36 (KHTML, like Gecko) '
                  'Chrome/43.0.2357.130 Safari/537.36',
    'Host': 'leetcode.com'
}

PROCESS_COUNT_LIMIT = 10

ENCODING = 'utf-8'

# TODO: need add other language support

LANG_SETTING = {
    'cpp':{
        'extension_name':'cpp',
        'prefix':'/**',
        'middle':' * ',
        'suffix':' */'
    },
    'c':{
        'extension_name':'c',
        'prefix':'/**',
        'middle':' * ',
        'suffix':' */'
    },
    'python':{
        'extension_name':'py',
        'prefix':'# ',
        'middle':'# ',
        'suffix':'# '
    },
}

LANG_EXTENTION = {v['extension_name']:k for k,v in LANG_SETTING.items()}


DIFFICULTYS = ['Easy','Medium','Hard']

LEETCODE_JSON_PATH = './config/leetcode.json'

LOCAL_FOLDER_PATH = './leetcode-problems'

CONFIG_FILE_PATH = './config/config.ini'
MD_TEMPLATE_PATH = './config/readme.md.temp'
