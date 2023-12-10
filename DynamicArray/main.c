#include <stdio.h>
#include <stdlib.h>
#include "dynamicArray.h"
#include <pthread.h>

#define DEFAULT_NUM    10

typedef struct StuInfo
{
    int age;
    char sex;
} StuInfo;

int main(int argc, const char *argv[])
{
#if 0
    DynamicArray array;
    /* 初始化 */
    dynamicArrayInit(&array);
    int arrayCapacity = 0;
    dynamicArrayGetCapacity(&array, &arrayCapacity);
    printf("arrayCapacity:%d\n", arrayCapacity);


    /* 插入 */
    for (int idx = 1; idx <= DEFAULT_NUM << 1; idx++)
    {
        dynamicArrayInsert(&array, idx);
    }
    dynamicArrayInsert(&array, 666);

    int arraySize = 0;
    dynamicArrayGetSize(&array, &arraySize);
    printf("arraySize:%d\n", arraySize);

    arrayCapacity = 0;
    dynamicArrayGetCapacity(&array, &arrayCapacity);
    printf("arrayCapacity:%d\n", arrayCapacity);

    /* 打印动态数组数据 */
    int val = 0;
    for (int idx = 0; idx < arraySize; idx++)
    {
        dynamicArrayGetAppointPosVal(&array, idx, &val);
        printf("val:%d\t", val);
    }
    printf("\n");

#if 0
    dynamicArrayDelAppointPos(&array, 0);

    dynamicArrayGetSize(&array, &arraySize);
    printf("arraySize:%d\n", arraySize);
    for (int idx = 0; idx < arraySize; idx++)
    {
        dynamicArrayGetAppointPosVal(&array, idx, &val);
        printf("val:%d\t", val);
    }
    printf("\n");
#endif
    for (int idx = 0; idx < DEFAULT_NUM + 5; idx++)
    {
        dynamicArrayDelAppointPos(&array, 0);
    }
    dynamicArrayGetSize(&array, &arraySize);
    printf("arraySize:%d\n", arraySize);

    dynamicArrayGetCapacity(&array, &arrayCapacity);
    printf("arrayCapacity:%d\n", arrayCapacity);


    for (int idx = 0; idx < arraySize; idx++)
    {
        dynamicArrayGetAppointPosVal(&array, idx, &val);
        printf("val:%d\t", val);
    }
    printf("\n");

    
    dynamicArrayDestory(&array);
#else
    StuInfo stu1, stu2, stu3;

    {
        stu1.age = 10;
        stu1.sex = 'm';
    
    }
    {
        stu2.age = 20;
        stu2.sex = 'f';
    }
    {
        stu3.age = 30;
        stu3.sex = 'm';
    }

    /* 动态数组 */
    DynamicArray array;
    /* 初始化 */
    dynamicArrayInit(&array);
    int arrayCapacity = 0;
    dynamicArrayGetCapacity(&array, &arrayCapacity);
    printf("arrayCapacity:%d\n", arrayCapacity);

    /* 插入 */
    for (int idx = 1; idx <= DEFAULT_NUM << 1; idx++)
    {
        dynamicArrayInsert(&array, (void *)&stu1);
    }

    int pos = 0;
    StuInfo * info = NULL;
    dynamicArrayGetAppointPosVal(&array, pos, (void*)&info);
    printf("info.age = %d\n", info->age);
    printf("info.age = %c\n", info->sex);
    
#endif
    return 0;
}