#include <stdio.h>
#include <stdlib.h>
#include "dynamicArray.h"
#include <pthread.h>

#define DEFAULT_NUM    10

int main(int argc, const char *argv[])
{
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

    return 0;
}