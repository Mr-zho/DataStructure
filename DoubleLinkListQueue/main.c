#include <stdlib.h>
#include <stdio.h>
#include "doublelinklistQueue.h"

#include <pthread.h>

#define linkList_NUM 3

int main()
{
    doubleLinkListQueue *queueList;
    doublelinklistQueueInit(&queueList);

    for (int idx = 1; idx <= linkList_NUM; idx++)
    {
        doublelinklistQueuePush(queueList, idx);
    }
    int queueSize = 0;
    doublelinklistQueueSize(queueList, &queueSize);
    printf("queueSize:%d\n", queueSize);

    int queueVal = 0;
    while (doublelinklistQueueSize(queueList, &queueSize))
    {
        doublelinklistQueueTop(queueList, &queueVal);
        doublelinklistQueuePop(queueList);
    }
    doublelinklistQueueSize(queueList, &queueSize);
    printf("queueSize:%d\n", queueSize);

    doublelinklistQueueDestory(queueList);
}