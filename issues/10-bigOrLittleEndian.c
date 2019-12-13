/********************************************************
 *   Copyright (C) 2017 All rights reserved.
 *
 *   Filename:10-bigOrLittleEndian.c
 *   Author  :Chuanqi.Duan
 *   Email   :chuanqiduan@foxmail.com
 *   Date    :2017-02-23 17:37
 *   Describe:验证大小端(高尾端/低尾端)
 ********************************************************/
#include <stdio.h>

union temp {
    short int a;
    char b;
} temp;


void WhichEndian()
{
    short int a = 1;
    char b = *(char *)&a;
    if (b == 1) //低地址存储的数据(低地址是否存储字节尾端)
    {
        printf("little endian\n");
    }
    else
    {
        printf("big endian\n");
    }
}

/*******************************************************
  联合体union的存放顺序是所有成员都从低地址开始存放，
  而且所有成员共享存储空间
 ********************************************************/
void WhichEndianI()
{
    temp.a = 0x1122;//0x11字节头端,0x22字节尾端
    if (temp.b == 0x11) //低地址是否存储字节头端
    {
        printf("big endian\n");
    }
    else
    {
        printf("little endian\n");
    }
}

int main()
{
    WhichEndian();
    WhichEndianI();
    return 0;
}
