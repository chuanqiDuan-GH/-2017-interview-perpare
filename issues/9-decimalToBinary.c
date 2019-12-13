/********************************************************
 *   Copyright (C) 2017 All rights reserved.
 *   
 *   Filename:9-decimalToBinary.c
 *   Author  :Chuanqi.Duan
 *   Email   :chuanqiduan@foxmail.com
 *   Date    :2017-02-22 18:30
 *   Describe:十进制转换二进制
 ********************************************************/
#include <stdio.h>
#include <stdlib.h>

#define BINARYSIZE 32

void DecimalToBinary(int deNum, int *arr)
{
    if (NULL == arr)
        return;

    int digit = 0;

    int rDeNum = abs(deNum);

    while (rDeNum)
    {
        arr[digit] = rDeNum % 2;

/*
        if (deNum < 0)
        {
            arr[digit] = ~arr[digit];
        }
*/
        digit++;
        rDeNum /= 2;
    }

    do
    {
        printf("%d ", arr[--digit]);
    } while (digit);
}

int main()
{
    int arr[BINARYSIZE] = {0};
    int input;

    if (EOF == scanf("%d", &input))
    {
        printf("scanf err\n");
        return -1;    
    }

    DecimalToBinary(input, arr);
    return 0;
}
