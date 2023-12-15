#include <stdlib.h>
#include <stdio.h>
#include "doublelinklist.h"
#include <string.h>

#define linkList_NUM 3

typedef struct StuInfo
{
    int age;
    char sex;
} StuInfo;      // 28字节

void printData(void *arg)
{
    int data = *(int *)arg;
    printf("data:%d\n", data);
}

void printStruct(void *arg)
{
    StuInfo info = *(StuInfo*)arg;
    printf("info.age:%d\tinfo.sex:%c\n", info.age, info.sex);
    return ;
}

int main()
{
    linkList *list = NULL;
    doubleLinkListInit(&list);

#if 0
    /* 头插 */
    int ret = 0;
    int array1[linkList_NUM] = {1, 2, 3};
    for (int idx = 0; idx < linkList_NUM; idx++)
    {
        doubleLinkListHeadInsert(list, (void *)&(array1[idx]));
    }
    /* 指定位置插入 */
    int posVal = 666;
    ret = doubleLinkListAppointPosInsert(list, 1, &posVal);
    /* 尾插 */
    int array2[linkList_NUM] = {100, 200, 300};
    for (int idx = 0; idx < linkList_NUM; idx++)
    {
        doubleLinkListTailInsert(list, (void *)&(array2[idx]));
    }

    /* 顺序打印 */
    doubleLinkListSeqForeach(list, printData);

    /* 逆序打印 */
    doubleLinkListReverseForeach(list, printData);

    printf("\n");
    /* 头删 */
    doubleLinkListHeadDel(list);
    doubleLinkListSeqForeach(list, printData);
    doubleLinkListReverseForeach(list, printData);

    printf("\n");
    /* 尾删 */
    doubleLinkListTailDel(list);
    doubleLinkListSeqForeach(list, printData);
    doubleLinkListReverseForeach(list, printData);

    int *headVal = NULL;
    doubleLinkListGetHeadVal(list, (void **)&headVal);
    printf("headVal:%d\n", *headVal);

    int *tailVal = NULL;
    doubleLinkListGetTailVal(list, (void **)&tailVal);
    printf("tailVal:%d\n", *tailVal);

    int *appointPosVal = NULL;
    doubleLinkListGetAppointPosVal(list, 4, (void **)&appointPosVal);
    printf("appointPosVal:%d\n", *appointPosVal);
#else
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

    /* 头插 */
    for (int idx = 0; idx < linkList_NUM - 1; idx++)
    {
        doubleLinkListHeadInsert(list, (void *)&(buffer[idx]));
    }
    /* 尾插 */
    doubleLinkListTailInsert(list, (void *)&(buffer[2]));   

    int length = 0;
    doubleLinkListGetLength(list, &length);
    printf("length:%d\n", length);

    /* 打印结构体 */
    doubleLinkListSeqForeach(list, printStruct);
#endif
    doubleLinkListDestory(list);
}