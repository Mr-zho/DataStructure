#include <stdio.h>
#include <stdlib.h>
#include "dynamicArray.h"
#include <pthread.h>

#define DEFAULT_NUM    2

int main(int argc, const char *argv[])
{
    DynamicArray array;
    /* 初始化 */
    dynamicArrayInit(&array);


    /* 插入 */
    for (int idx = 1; idx <= DEFAULT_NUM << 1; idx++)
    {
        dynamicArrayInsert(&array, idx);
    }

    int arraySize = 0;
    dynamicArrayGetSize(&array, &arraySize);
    printf("arraySize:%d\n", arraySize);


    int val = 0;
    dynamicArrayGetAppointPosVal(&array, arraySize - 1, &val);
    printf("val:%d\n", val);
    dynamicArrayDestory(&array);

    return 0;
}