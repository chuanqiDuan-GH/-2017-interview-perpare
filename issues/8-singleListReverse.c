/********************************************************
 *   Copyright (C) 2017 All rights reserved.
 *   
 *   Filename:8-singleListReverse.c
 *   Author  :Chuanqi.Duan
 *   Email   :chuanqiduan@foxmail.com
 *   Date    :2017-02-21 22:44
 *   Describe:单链表逆序
 ********************************************************/
#include <stdio.h>
#include <stdlib.h>

#define LISTTYPE int

typedef struct ListNode
{
    LISTTYPE value;
    struct ListNode *pNext;
} Node, *pNode;

//增加节点
void AddList(LISTTYPE value, pNode *head)
{
    if (NULL == (*head))
    {
        *head = (pNode)malloc(sizeof(Node));
        (*head)->value = value;
        (*head)->pNext = NULL;
        return;
    }
    pNode new = (pNode)malloc(sizeof(Node));
    if (NULL == new)
    {
        return;
    }
    new->value = value;
    new->pNext = NULL;

    if (NULL == (*head))
    {
        *head = new;
    }
    else
    {
        /*
        //头插入
        new->pNext = (*head)->pNext;
        (*head)->pNext = new;
        */

        //尾插入
        pNode tmp = *head;
        while (NULL != tmp->pNext)
        {    
            tmp = tmp->pNext; 
        }
        tmp->pNext = new; 
    }
}

//反转
pNode Reverse(pNode head)
{
    if (NULL == head)
    {
        return head;
    }

    pNode tmp = head->pNext;
    pNode rear = head;
    pNode front = tmp;
    head->pNext = NULL;

    while (NULL != tmp)
    {
        tmp = tmp->pNext;
        front->pNext = rear;
        rear = front;
        front = tmp;
    }
    return rear;
}

//展示数据
void ShowList(pNode head)
{
    if (NULL == head)
    {
        return; 
    }

    pNode tmp = head;
    while (tmp)
    {
        printf("%d\n", tmp->value);
        tmp = tmp->pNext;
    }
}

//释放内存
void FreeList(pNode *head)
{
    if (NULL == (*head))
    {
        return; 
    }

    pNode tmp = (*head)->pNext;
    pNode del = *head;

    while (NULL != del)
    {
        free(del); 
        del = tmp;
        if (NULL != tmp)
        {
            tmp = tmp->pNext;
        }
    }
}

int main()
{
    pNode head = NULL;
    AddList(1, &head);
    AddList(2, &head);
    AddList(3, &head);
    AddList(4, &head);
    ShowList(head);

    //反转后的链表
    pNode rear = Reverse(head);
    ShowList(rear);

    FreeList(&rear);
    return 0;
}
