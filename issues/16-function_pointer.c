/********************************************************
*   Copyright (C) 2019 All rights reserved.
*   
*   Filename:function_pointer.c
*   Author  :Chuanqi.Duan
*   Email   :chuanqiDuan@foxmail.com
*   Date    :2019-12-01 23:37
*   Describe:函数指针测试
********************************************************/
#include <stdio.h>


typedef int(*PDO_MATH)(int, int);

int add(int np, int nn)
{
    return np + nn;    
}

int mins(int np, int nn)
{
    return np - nn;
}

int main()
{
    PDO_MATH func = add;
    printf("%d\n", func(1, 2));


    func = mins;
    printf("%d\n", func(2, 1));
    return 0;
}
