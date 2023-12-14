#include <stdlib.h>
#include <stdio.h>
#include "doublelinklistQueue.h"
#include <string.h>
#include <pthread.h>

#define linkList_NUM 3

typedef struct stu_info
{
    int age;
    char sex;
} stu_info;

int main()
{
#if 0
    /* 基本数据类型 */
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
#else
    /* 复合数据类型 */
    doubleLinkListQueue *queueList;
    doublelinklistQueueInit(&queueList);

    stu_info stu1;
    memset(&stu1, 0, sizeof(stu1));
    stu1.age = 10;
    stu1.sex = 'm';
    

    stu_info stu2;
    memset(&stu2, 0, sizeof(stu2));
    stu2.age = 20;
    stu2.sex = 'm';
    

    stu_info stu3;
    memset(&stu3, 0, sizeof(stu3));
    stu3.age = 30;
    stu3.sex = 'm';
    

    doublelinklistQueuePush(queueList, &stu1);
    doublelinklistQueuePush(queueList, &stu2);
    doublelinklistQueuePush(queueList, &stu3);

    int len = 0;
    doublelinklistQueueSize(queueList, &len);
    printf("len:%d\n", len);
    stu_info info;
    while (doublelinklistQueueSize(queueList, &len))
    {
        doublelinklistQueueTop(queueList, (void *)&info);
        printf("age:%d\tsex:%c\n", info.age, info.sex);
        doublelinklistQueuePop(queueList);
    }
    doublelinklistQueueSize(queueList, &len);
    printf("len:%d\n", len);
#endif
}