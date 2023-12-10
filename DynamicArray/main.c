#include <stdio.h>
#include <stdlib.h>
#include "dynamicArray.h"
#include <pthread.h>
#include <string.h>

#define DEFAULT_NUM    2
#define BUFFER_SIZE    20

typedef struct StuInfo
{
    int age;
    char sex;
    char name[BUFFER_SIZE];
} StuInfo;      // 28字节

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
#endif
    StuInfo stu1;
    StuInfo stu2;
    StuInfo stu3;
    // memset(&stu1, 0, sizeof(stu1));
    // memset(&stu2, 0, sizeof(stu2));
    // memset(&stu3, 0, sizeof(stu3));

    /* 模块化初始化 */
#if 1
    {
        stu1.age = 10;
        stu1.sex = 'm';
        char *name = "yuchen";
        strncpy(stu1.name, name, sizeof(stu1.name) - 1);
    }
#endif

#if 1
    /* 模块化初始化 */
    {
        stu2.age = 20;
        stu2.sex = 'f';
        char *name = "mr_shuo";
        strncpy(stu2.name, name, sizeof(stu2.name) - 1);
    }
#endif

#if 1
    /* 模块化初始化 */
    {
        stu3.age = 30;
        stu3.sex = 'm';
        char *name = "mr_yu";
        strncpy(stu3.name, name, sizeof(stu3.name) - 1);
    }
#endif

#if 1
    /* 动态数组 */
    DynamicArray array;
    /* 初始化 */
    dynamicArrayInit(&array);
    int arrayCapacity = 0;
    dynamicArrayGetCapacity(&array, &arrayCapacity);
    printf("arrayCapacity:%d\n", arrayCapacity);

    /* 插入 */
    StuInfo buffer[BUFFER_SIZE] = {stu1, stu2, stu3};

    for (int idx = 0; idx < (DEFAULT_NUM << 1) - 1; idx++)
    {
        printf("insert buffer[%d].age:%d\n", idx, buffer[idx].age);
        dynamicArrayInsert(&array, (void *)&buffer[idx]);
    }

    int arraySize = 0;
    dynamicArrayGetSize(&array, &arraySize);
    printf("arraySize:%d\n", arraySize);
#endif

#if 1
    int pos = 0;
    StuInfo * info = NULL;
    for (int idx = 1; idx < (DEFAULT_NUM << 1); idx++)
    {
        dynamicArrayGetAppointPosVal(&array, idx - 1, (void*)&info);
        printf("info.age = %d\n", info->age);
        printf("info.age = %c\n", info->sex);
    }
#endif
    return 0;
}