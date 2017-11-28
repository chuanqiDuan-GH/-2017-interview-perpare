/********************************************************
*   Copyright (C) 2017 All rights reserved.
*   
*   Filename:sscanfTest.c
*   Author  :Chuanqi.Duan
*   Email   :chuanqiduan@foxmail.com
*   Date    :2017-11-28 22:49
*   Describe:使用strstr/strchr和sscanf处理字符串
********************************************************/
#include <stdio.h>
#include <string.h>

void func()
{
    //char str[128] = "HOME,100; right,200; left,300; home,400; sleep,1200000;";
    char str[128] = "HOME,100;right,200;left,300;home,400;sleep,1200000;";
    char cmd[16] = "0";
    int delay = 0;
    char *tmp = str;

//处理有空格的字符串
#if 0
    while(NULL != tmp)
    {
	sscanf(tmp, "%[^,],%d", cmd, &delay);
    	printf("%s\n", cmd);
    	printf("%d\n", delay);
	tmp = strstr(tmp, " ");
	if(NULL == tmp++)
	    break;
    }
#endif

//处理没有空格的字符串
    while(NULL != tmp)
    {
	sscanf(tmp, "%[^,],%d", cmd, &delay);
    	printf("%s\n", cmd);
    	printf("%d\n", delay);
	tmp = strchr(tmp, ';');
	if(NULL == tmp++)
	    break;
    }

}

int main()
{
    func();
    return 0;
}
