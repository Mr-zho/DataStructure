#include <stdlib.h>
#include <stdio.h>
#include "doublelinklist.h"
#include <pthread.h>

#define linkList_NUM 10

int main()
{
    linkList *list = NULL;
    linkListInit(&list);
    
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
    /* 中间插 */
    ret = linkListAppointPosInsert(list, 0, 666);

    linkListHeadInsert(list, 7);

    linkListTailInsert(list, 888);

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
    linkListSeqForeach(list);

    /* 逆序打印 */
    linkListReverseForeach(list);
}