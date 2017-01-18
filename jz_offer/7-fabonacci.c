/********************************************************
*   Copyright (C) 2017 All rights reserved.
*   
*   Filename:7-fabonacci.c
*   Author  :Chuanqi.Duan
*   Email   :chuanqiduan@foxmail.com
*   Date    :2017-01-18 23:31
*   Describe:剑指offer-Q9-费波那契数列
********************************************************/
#include <stdio.h>

#if 0
/*从顶层到底层*/
unsigned int FabonacciTop2Bottom(unsigned int n)
{
    if(n <3)
	return n;

    return FabonacciTop2Bottom(n-1) + FabonacciTop2Bottom(n-2);
}
#endif

/*从底层到顶层*/
unsigned int FabonacciBottom2Top(unsigned int n)
{
    unsigned int firNum = 0;
    unsigned int secNum = 1;
    unsigned int count = 2;
    unsigned int ret;

    if(n < 3)
	return n;

    while(count < n)
    {
	ret = firNum + secNum; 
	firNum = secNum;
	secNum = ret;	

	count++;
    }

    return ret;
}

/*fabonacci第n项*/
int main()
{
    int n = 4;
    //printf("%d\n", FabonacciTop2Bottom(n));
    printf("%d\n", FabonacciBottom2Top(n));
}
