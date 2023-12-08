#ifndef __LINKLIST_H_
#define __LINKLIST_H_

/* 状态码 */
enum STATUSCODE
{
    ON_SUCCESS,
    NULL_PTR,
    MALLOC_ERR,
    INVAILD_ACCESS,
};

typedef struct node
{
    int val;                /* 数据 */
    struct node * prev;     /* 前置指针 */
    struct node * next;     /* 后置指针 */
} Node;

typedef struct linkList
{
    Node *head;
    Node *tail;
    int len;
} linkList;

/* 链表的初始化 */
int linkListInit(linkList **pList);

/* 头插 */
int linkListHeadInsert(linkList *pList, int val);

/* 尾插 */
int linkListTailInsert(linkList *pList, int val);

/* 指定位置插入 */
int linkListAppointPosInsert(linkList *pList, int pos, int val);

/* 获取链表的数据 */
int linkListGetLength(linkList *pList, int *pLen);

/* 顺序遍历链表 */
int linkListSeqForeach(linkList *pList);

/* 逆序遍历链表 */
int linkListReverseForeach(linkList *pList);

#endif  //__LINKLIST_H_