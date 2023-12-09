#include <stdlib.h>
#include <stdio.h>
#include "doublelinklist.h"
#include <pthread.h>

#define linkList_NUM 3

int main()
{
    linkList *list = NULL;
    doubleLinkListInit(&list);
    
    int ret = 0;
#if 0
    for (int idx = 1; idx <= linkList_NUM; idx++)
    {
        ret = linkListAppointPosInsert(list, 0, idx);
        if (ret != ON_SUCCESS)
        {
            printf("ret:%d\n", ret);
        }
    }
#endif

    for (int idx = 1; idx <= linkList_NUM; idx++)
    {
        doubleLinkListHeadInsert(list, idx);
    }

    /* 指定位置插入 */
    ret = doubleLinkListAppointPosInsert(list, 1, 666);

    for (int idx = 100; idx <= linkList_NUM + 100; idx++)
    {
        doubleLinkListTailInsert(list, idx);
    }

    // int length = 0;
    // for (int idx = 100; idx <= 100 + linkList_NUM; idx++)
    // {
    //     linkListGetLength(list, &length);
    //     ret = linkListAppointPosInsert(list, length, idx);
    //     if (ret != ON_SUCCESS)
    //     {
    //         printf("ret:%d\n", ret);
    //     }
    // }
    /* 顺序打印 */
    doubleLinkListSeqForeach(list);

    /* 逆序打印 */
    doubleLinkListReverseForeach(list);

    printf("\n");
    /* 头删 */
    doubleLinkListHeadDel(list);
    doubleLinkListSeqForeach(list);
    doubleLinkListReverseForeach(list);

    printf("\n");
    /* 尾删 */
    doubleLinkListTailDel(list);
    doubleLinkListSeqForeach(list);
    doubleLinkListReverseForeach(list);

    doubleLinkListDestory(list);
}