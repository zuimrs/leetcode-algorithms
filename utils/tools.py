#!/usr/bin/python
# -*- coding: utf-8 -*-
# FILE: tools.py
# AUTHOR: zuimrs

import json
import os


def handle_requests(session,url,method = 'GET',data = None,cookies = None):
    """
    处理request信息
    """
    from .common import PROXIES
    from .common import HEADERS
    result = None
    try:
        if method == 'GET':
            result = session.get(url,headers = HEADERS,data = data,proxies = PROXIES,cookies = cookies)
        elif method == 'POST':
            result = session.post(url,headers = HEADERS,data = data,proxies = PROXIES,cookies = cookies)
    except :
        # TODO: 修改config，添加代理信息
        print("\nERROR:Connection Failed,you may set proxy by using [ python manage.py config ] command.")
        exit(0)
    return result



# TODO: 暂时先这样用，之后修改
def get_all_folders(folder_path):
    return os.listdir(folder_path)

def get_all_files(folder_path):
    return os.listdir(folder_path)

def judge_lang(filename):
    """
    根据文件名判断对应的编程语言
    """
    from .common import LANG_EXTENTION
    try:
        s = filename.split('.')[1]
        lang = LANG_EXTENTION[s]
    except:
        return None
    return lang

def judge_file_exists(file_path,file_name):
    file_list = os.listdir(file_path)
    for item in file_list:
        if item == file_name:
            return True
    return False

def read_from_file(filepath):
    try:
        fileObject = open(filepath)
        content = fileObject.read()
    except:
        print "\nERROR: File {} not exists".format(filepath)
        return None
    return content

def write_into_file(filepath,content):
    from .common import ENCODING
    try:
        fileObject = open(filepath,'wb')
        fileObject.write(content.encode(ENCODING))
    except:
        print "\nERROR: Write file {} failed.".format(filepath)
        exit(0)
    return True



def save_into_json(file_path,content):
    dirname = os.path.split(file_path)[0]
    basename = os.path.split(file_path)[1]
    jsonObject = json.dumps(content,ensure_ascii=True)
    # 如果文件夹不存在,递归创建目录
    if os.path.exists(dirname) == False:
        try:
            os.makedirs(dirname)
        except OSError as exc:
            if exc.errno == errno.EEXIST and os.path.isdir(dirname):
                pass
            else:
                print "\nERROR: Create folder %s failed." %(dirname)
                exit(0)
    # 文件夹存在，则写json
    try:
        fileObject = open(file_path, 'w')
        fileObject.write(jsonObject)
        fileObject.close()
    except:
        print "\nERROR: Create %s failed."%(file_path)
        exit(0)

def load_from_json(file_path):
    # 读json
    try :
        fileObject = open(file_path, 'r')
        json_dict = json.load(fileObject)
    except:
        print "\nERROR: Load leetcode.json failed."
        exit(0)
    return json_dict
