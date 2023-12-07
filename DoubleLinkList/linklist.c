#include "linklist.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


/* 链表的初始化 */
int linkListInit(linkList **pList)
{
    int ret = 0;
    linkList *plist = (linkList *)malloc(sizeof(linkList) * 1);    
    if (!plist)
    {
        return -1;
    }
    /* 清空内存中的脏数据 */
    memset(plist, 0, sizeof(linkList) * 1);
    
    plist->head = (Node *)malloc(sizeof(Node) * 1);
    if (!(plist->head))
    {
        return -1;
    }
    /* 清空内存中的脏数据 */
    memset(plist->head, 0, sizeof(Node) * 1);
    /* 初始化链表 */
    plist->len = 0;
    /* 初始化虚拟结点*/
    plist->head->val = 0;
    plist->head->next = NULL;
    /* 初始化尾指针 */
    plist->tail = plist->head;

    *pList = plist;
    return ret;
}

/* 头插 */
int linkListHeadInsert(linkList *pList, int val)
{
    return linkListAppointPosInsert(pList, 0, val);
}

/* 尾巴 */
int linkListTailInsert(linkList *pList, int val)
{
    int pos = pList->len;
    return linkListAppointPosInsert(pList, pos, val);
}

/* 指定位置插 */
int linkListAppointPosInsert(linkList *pList, int pos, int val)
{
    int ret = 0;
    if (!pList)
    {
        return NULL_PTR;
    }
    Node *newnode = (Node *)malloc(sizeof(Node) * 1);
    if (!newnode)
    {
        return MALLOC_ERR;
    }
    memset(newnode, 0, sizeof(Node));
    /* 维护新的节点 */
    newnode->val = val;
    newnode->next = NULL;
    newnode->prev = NULL;


    /* 判断位置是否合法 */
    if (pos < 0 || pos > pList->len)
    {
        return INVAILD_ACCESS;
    }

    Node * travel = pList->head;
    while (pos)
    {
        pos--;
        travel = travel->next;
    }

    /* 没有结点的情况下 */
    if (pList->len == 0 || pos == pList->len)
    {
        newnode->next = travel->next;       // 1
        newnode->prev = travel;             // 3
        travel->next = newnode;             // 4
    }
    else
    {
        newnode->next = travel->next;       // 1
        travel->next->prev = newnode;       // 2
        newnode->prev = travel;             // 3
        travel->next = newnode;             // 4
    }

    /* 更新长度 */
    (pList->len)++;
    return ret;
}

/* 获取链表的数据 */
int linkListGetLength(linkList *pList, int *pLen)
{
    int ret;
    if (!pList || !pLen)
    {
        return -1;
    }
    /* 解引用 */
    *pLen = pList->len;
    return ret;
}


/* 顺序遍历链表 */
int linkListSeqForeach(linkList *pList)
{
    int ret = 0;
    if (!pList)
    {
        return -1;
    }

    Node *travel = pList->head->next;
    while(travel != NULL)
    {
        printf("%d\t->", travel->val);
        travel = travel->next;
    }
    printf("\n");
    return ret;
}


int linkListReverseForeach(linkList *pList)
{
    int ret = 0;
    if (!pList)
    {
        return -1;
    }

    Node *travel = pList->head;
    while(travel->next != NULL)
    {
        // printf("%d\t->", travel->val);
        travel = travel->next;
    }

    while (travel != pList->head)
    {
        printf("%d\t->", travel->val);
        travel = travel->prev;
    }
    printf("\n");
    
    return ret;
}