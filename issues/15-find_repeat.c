/********************************************************
*   Copyright (C) 2019 All rights reserved.
*   
*   Filename:find_repeat.c
*   Author  :Chuanqi.Duan
*   Email   :chuanqiDuan@foxmail.com
*   Date    :2019-11-30 21:41
*   Describe:
*            1.数组a[N],1~N-1这N-1个数存放在a[n]中，其中某个数重复一次，找出重复数字，时间复杂度必须是O(n)
*            2.数组a[N],0~N-2这N-1个数存放在a[n]中，其中某个数重复一次，找出重复数字，时间复杂度必须是O(n)
********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int FindRepeat(int *arr, int n)
{
    //入参校验
    if (NULL == arr || n <= 1) 
    {
        return -1;
    }

    int idx, result = -1, count = 0;

    /*
     根据arr中的内容获取最大value,用来做新数组的长度 

     以上逻辑问题背景下,存在两个问题
     1.内存越界访问的场景
        使用最大值n-1作为新数组长度申请内存前提下,再使用arr_rep[n-1]访问,会导致heap-buffer-overflow
     2.无效逻辑
        完全不需要通过遍历获得最大值,通过题干可知n-1为最大值

     所以基于以上两个原因这段逻辑注释
     */
    /*
    int saveValue = arr[0];

    for (idx = 0; idx < n; idx++)
    {
        if (saveValue < arr[idx])
        {
            saveValue = arr[idx];
        }
    }
    int *arr_rep = (int *)malloc(saveValue * sizeof(int));
    */

    //申请长度为n*sizeof(int)内存,作为处理重复数字的数组,则没有heap-buffer-overflow的风险
    int *arr_rep = (int *)malloc(n * sizeof(int));
    memset(arr_rep, 0, n * sizeof(int));

    //以arr的value为下标遍历arr_rep
    for (idx = 0; idx < n; idx++)
    {
        //默认arr_rep的value全部为0
        if (arr_rep[arr[idx]] == 0)
        {
            //处理重复数字为0的情况,结合场景2
            if (arr[idx]  == 0)
            {
                count++;
            }
            //arr[idx]不为0,那么就将arr[idx]的value刷到新数组中
            else
            {
                arr_rep[arr[idx]] = arr[idx];
            }

            //如果count大于1,说明arr_rep[0]再次被访问,也说明arr中存在重复的0,跳出循环,返回结果
            if (count > 1)
            {
                result = 0;
                break;
            }
        } 
        //arr_rep[arr[idx]]已经有value,并且再被访问到,即说明arr中该值重复,跳出循环,返回结果
        else
        {
            result = arr_rep[arr[idx]];
            break;
        }
    }
    
    printf("%d\n", result);
    free(arr_rep);
    return result;
}

int main()
{

    
    //测试数据,针对场景1
    //int arr[6] = {4, 2, 3, 1, 5, 5};

    //测试数据,针对场景2
    int arr[6] = {4, 2, 3, 1, 0, 0};

    printf("%d\n", FindRepeat(arr, 6));
    return 0;
}
