/********************************************************
*   Copyright (C) 2019 All rights reserved.
*   
*   Filename:dynamic.c
*   Author  :Chuanqi.Duan
*   Email   :chuanqiduan@foxmail.com
*   Date    :2019-12-25 20:51
*   Describe:动态库调用
********************************************************/
#include <stdio.h>
#include "share.h"

void Dynamic()
{
    ShareFunc(__FILE__);
}


int main()
{
    Dynamic();
    return 0;
}

