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


    /* 插入 */
    for (int idx = 1; idx <= (DEFAULT_NUM << 2); idx++)
    {
        dynamicArrayInsert(&array, idx);
    }

    /* */
    int val = 0;
    dynamicArrayGetAppointPosVal(&array, 25, &val);
    printf("val:%d\n", val);


    int capacity = 0, size = 0;
    dynamicArrayGetInfo(&array, &capacity, &size);
    printf("capacity:%d, size:%d\n", capacity, size);

    return 0;
}