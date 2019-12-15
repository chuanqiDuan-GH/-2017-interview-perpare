/********************************************************
*   Copyright (C) 2019 All rights reserved.
*   
*   Filename:list_delete.c
*   Author  :Chuanqi.Duan
*   Email   :chuanqiduan@foxmail.com
*   Date    :2019-12-08 21:13
*   Describe:给定单向链表的头指针和一个节点指针,定义一个函数在O(1)时间内删除该节点
********************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct LISTNODE {
    int value;
    struct LISTNODE *pNext;
}ListNode, *pListNode;

void DeleteListNode(pListNode pHead, pListNode pCurNode)
{
    if (NULL == pHead || NULL == pCurNode) {
        printf("params err\n");
        return;
    }

    pListNode pTmp = pCurNode;
    pListNode isDel = pTmp->pNext; 

    if (NULL != pTmp->pNext) {
        pTmp->value = isDel->value;
        pTmp->pNext = isDel->pNext;

        free(isDel);
        isDel = NULL;
    } else if (NULL == pTmp->pNext) {
        if (pHead != pTmp) {
            pListNode tmp = pHead;

            while (NULL != tmp->pNext) {
                tmp = tmp->pNext;
            }

            tmp->pNext = NULL;
            isDel = pTmp;
            free(isDel);
            isDel = NULL;
        } else {
            free(pHead);
            free(isDel);
            pHead = NULL;
            isDel = NULL;
        }
    }
}

pListNode InsertList(pListNode pHead, int value)
{
    if (NULL == pHead) {
        pHead = (pListNode)malloc(sizeof(ListNode));
        pHead->value = 0;
        pHead->pNext = NULL;
        return pHead;
    }

    pListNode pTmpNode = pHead;

    pListNode pNewNode = (pListNode)malloc(sizeof(ListNode));
    pNewNode->value = value;
    pNewNode->pNext = NULL;

    while (NULL != pTmpNode->pNext) {
        pTmpNode = pTmpNode->pNext;
    }

    pTmpNode->pNext = pNewNode;
    return pHead;
}

int main()
{
    pListNode pHead = NULL;

    pHead = InsertList(pHead, 0);
    pHead = InsertList(pHead, 1);
    pHead = InsertList(pHead, 2);
    pHead = InsertList(pHead, 3);

    pListNode pTmp = pHead->pNext;
    pListNode pDel = pTmp->pNext;

    DeleteListNode(pHead, pDel);

/*
    pTmp->value = pTmp->pNext->value;
    pTmp->pNext = pTmp->pNext->pNext;
    free(pDel);
    pDel = NULL;
    */

    pTmp = pHead;
    while (NULL != pTmp->pNext) {
        printf("%d ", pTmp->value);
        pDel = pTmp;
        pTmp = pTmp->pNext;
        free(pDel);
        pDel= NULL;
    }
    printf("%d ", pTmp->value);
    free(pTmp);
    pTmp = NULL;

    return 0;
}
