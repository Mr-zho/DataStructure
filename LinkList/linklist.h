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
    struct node * next;     /* 指针 */
} Node;

typedef struct linkList
{
    Node *head;
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

/* 遍历链表 */
int linkListForeach(linkList *pList);

/* 头删 */
int linkListHeadDel(linkList *pList);

/* 尾删 */
int linkListTailDel(linkList *pList);

/* 按指定位置删除 */
int linkListAppointPosDel(linkList *pList, int pos);

/* 链表销毁 */
int linkListDestroy(linkList *pList);

/* 链表删除指定数据 */
int linkListAppointValDel(linkList *pList, int val);

#endif  //__LINKLIST_H_