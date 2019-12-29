/********************************************************
*   Copyright (C) 2019 All rights reserved.
*   
*   Filename:share_func.c
*   Author  :Chuanqi.Duan
*   Email   :chuanqiduan@foxmail.com
*   Date    :2019-12-25 20:50
*   Describe:动态库&静态库编译测试
********************************************************/
#include <stdio.h>

void ShareFunc(char *fileName)
{
    printf("called by %s\n", fileName);
}
