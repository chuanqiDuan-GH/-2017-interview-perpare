/********************************************************
 *   Copyright (C) 2017 All rights reserved.
 *   
 *   Filename:6-minNumOfGyrateArr.c
 *   Author  :Chuanqi.Duan
 *   Email   :chuanqiduan@foxmail.com
 *   Date    :2017-01-13 22:58
 *   Describe:剑指offer-Q8-旋转数组的最小数字
 ********************************************************/
#include <stdio.h>

/*普通情况处理*/
void findMinNumOfGyrateArr(int *arr, int len)
{
    if(NULL == arr || len == 0)
    {
	printf("fatal error\n"); 
	return;
    }

    int posFront = 0;
    int posRear = len-1;
    int posMid = len/2;

    while(posFront < posRear-1)
    {
	//printf("%d %d %d \n", arr[posFront], arr[posMid], arr[posRear]);
	if(arr[posFront] < arr[posMid])
	    posFront = posMid;	
	else
	    posRear = posMid;

	posMid = (posRear-posFront)/2 + posFront;
    }

    printf("min num: %d\n", arr[posRear]);
}

int main()
{
    /*普通情况*/
    int arr[7] = {4, 5, 6, 7, 1, 2, 3};
    int len = sizeof(arr)/sizeof(int);

    findMinNumOfGyrateArr(arr, len);
    return 0;
}

