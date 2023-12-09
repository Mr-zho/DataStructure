#include <stdlib.h>
#include <stdio.h>
#include "linklist.h"
#include <pthread.h>

#define linkList_NUM 3

int main()
{
    linkList *list = NULL;
    linkListInit(&list);

    int ret = 0;
    /* 头插 */
    for (int idx = 1; idx < linkList_NUM; idx++)
    {
        ret = linkListHeadInsert(list, idx);
        if (ret != ON_SUCCESS)
        {
            printf("ret:%d\n", ret);
        }
    }
    /* 按指定位置插入 */
    ret = linkListAppointPosInsert(list, 2, 666);

    int length = 0;
    for (int idx = 100; idx <= 100 + linkList_NUM; idx++)
    {
        linkListTailInsert(list, idx);
        if (ret != ON_SUCCESS)
        {
            printf("ret:%d\n", ret);
        }
    }
    linkListForeach(list);

    /* 尾删 */
    linkListTailDel(list);
    linkListForeach(list);

    /* 头删 */
    linkListHeadDel(list);
    linkListForeach(list);
}