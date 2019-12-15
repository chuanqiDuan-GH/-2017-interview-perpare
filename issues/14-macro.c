/********************************************************
*   Copyright (C) 2019 All rights reserved.
*   
*   Filename:macro.c
*   Author  :Chuanqi.Duan
*   Email   :chuanqiDuan@foxmail.com
*   Date    :2019-11-20 23:43
*   Describe:测试宏函数实现swap
********************************************************/
#include <stdio.h>

#define swap(x, y) \
x = x + y; \
y = x - y; \
x = x - y;

int main ()
{
    int a = 5;
    int b = 6;

    swap(a, b);
    printf("%d, %d\n", a, b);
    return 0;
}
