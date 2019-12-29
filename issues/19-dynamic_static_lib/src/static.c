/********************************************************
*   Copyright (C) 2019 All rights reserved.
*   
*   Filename:static.c
*   Author  :Chuanqi.Duan
*   Email   :chuanqiduan@foxmail.com
*   Date    :2019-12-25 20:51
*   Describe:
********************************************************/
#include <stdio.h>
#include "share.h"

void Static()
{
    ShareFunc(__FILE__);
}

int main()
{
    Static();
    return 0;
}
