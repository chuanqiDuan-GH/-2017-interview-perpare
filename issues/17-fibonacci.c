/********************************************************
*   Copyright (C) 2019 All rights reserved.
*   
*   Filename:fibonacci.c
*   Author  :Chuanqi.Duan
*   Email   :chuanqiduan@foxmail.com
*   Date    :2019-12-06 22:32
*   Describe:青蛙跳台阶(斐波那契)
********************************************************/
#include <stdio.h>


int FibaFunc(int n)
{
    if (n == 1 || n == 2) {
        return n;
    }

    int f1 = 1;
    int f2 = 2;
    int ft = 0;

    int count = 3;
    while (count++ <= n) {
        ft = f1;
        f1 = f2;
        f2 = ft + f1;
    }
    return f2;
}

int main ()
{
    printf("%d\n", FibaFunc(5));
    return 0;
}
