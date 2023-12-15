#include <stdlib.h>
#include <stdio.h>
#include "linklist.h"
#include <pthread.h>

#define linkList_NUM 3


typedef struct StuInfo
{
    int age;
    char sex;
} StuInfo;      // 28字节

void printStruct(void *arg)
{
    StuInfo *info = (StuInfo*)arg;
    printf("info->age:%d\tinfo->sex:%c\n", info->age, info->sex);
    return;
}


void printData(void *arg)
{
    int data = *(int *)arg;
    printf("data:%d\n", data);
}

int main()
{
    linkList *list = NULL;
    linkListInit(&list);

#if 0
    int ret = 0;
    int array1[linkList_NUM] = {1, 2, 3};
    /* 头插 */
    for (int idx = 0; idx < linkList_NUM; idx++)
    {
        ret = linkListHeadInsert(list, (void *)&array1[idx]);
        if (ret != ON_SUCCESS)
        {
            printf("ret:%d\n", ret);
        }
    }

    int length = 0;
    int array2[linkList_NUM] = {100, 200, 300};
    for (int idx = 0; idx < linkList_NUM; idx++)
    {
        linkListTailInsert(list, (void *)&array2[idx]);
        if (ret != ON_SUCCESS)
        {
            printf("ret:%d\n", ret);
        }
    }
    linkListForeach(list, printData);

    int linkLen = 0;
    linkListGetLength(list, &linkLen);
    printf("len:%d\n", linkLen);
#endif

#if 0
    /* 尾删 */
    linkListTailDel(list);
    linkListForeach(list);
    linkListGetLength(list, &linkLen);
    printf("len:%d\n", linkLen);

    /* 头删 */
    linkListHeadDel(list);
    linkListForeach(list);
    linkListGetLength(list, &linkLen);
    printf("len:%d\n", linkLen);
#endif

#if 0
    StuInfo stu1;
    StuInfo stu2;
    StuInfo stu3;
    memset(&stu1, 0, sizeof(stu1));
    memset(&stu2, 0, sizeof(stu2));
    memset(&stu3, 0, sizeof(stu3));

    /* 模块化初始化 */
#if 1
    {
        stu1.age = 10;
        stu1.sex = 'm';
    }


    /* 模块化初始化 */
    {
        stu2.age = 20;
        stu2.sex = 'f';
    }

    /* 模块化初始化 */
    {
        stu3.age = 30;
        stu3.sex = 'm';
    }
#endif

    /* 结构体数组 */
    StuInfo buffer[linkList_NUM] = {stu1, stu2, stu3};

    int ret = 0;
    /* 头插 */
    for (int idx = 0; idx < linkList_NUM; idx++)
    {
        ret = linkListHeadInsert(list, (void *)&(buffer[idx]));
        if (ret != ON_SUCCESS)
        {
            printf("ret:%d\n", ret);
        }
    }
    int len = 0;
    linkListGetLength(list, &len);
    printf("len:%d\n", len);

    /* 遍历操作 : 自实现打印函数 */
    linkListForeach(list, printStruct);
#endif
    /* 链表销毁 */
    linkListDestroy(list);
}