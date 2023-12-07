#include <stdlib.h>
#include <stdio.h>
#include "linklist.h"
#include <pthread.h>

#define linkList_NUM 10

int main()
{
    linkList *list = NULL;
    linkListInit(&list);

    int ret = 0;
    for (int idx = 1; idx <= linkList_NUM; idx++)
    {
        ret = linkListAppointPosInsert(list, 0, idx);
        if (ret != ON_SUCCESS)
        {
            printf("ret:%d\n", ret);
        }
    }

    /* 中间插 */
    ret = linkListAppointPosInsert(list, 10, 666);

    int length = 0;
    for (int idx = 100; idx <= 100 + linkList_NUM; idx++)
    {
        linkListGetLength(list, &length);
        ret = linkListAppointPosInsert(list, length, idx);
        if (ret != ON_SUCCESS)
        {
            printf("ret:%d\n", ret);
        }
    }
    linkListForeach(list);
}