#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayStack.h"

#define DEFAULT_NUM    3

typedef struct StuInfo
{
    int age;
    char sex;
} StuInfo;      // 28字节

int main(int argc, const char *argv[])
{
    ArrayStack Stack;
    arrayStackInit(&Stack);
#if 0
    int array1[DEFAULT_NUM] = {1, 2, 3};
    for (int idx = 0; idx < DEFAULT_NUM; idx++)
    {
        arrayStackPush(&Stack, &array1[idx]);
    }
    int stackSize = 0;
    arrayStackGetSize(&Stack, &stackSize);
    printf("stack size:%d\n", stackSize);

    
    int *stackTopVal = NULL;
    while (arrayStackGetSize(&Stack, &stackSize))
    {
        arrayStackTop(&Stack, (void *)&stackTopVal);
        printf("stack top:%d\n", *stackTopVal);
        arrayStackPop(&Stack);
    }
    arrayStackGetSize(&Stack, &stackSize);
    printf("stack size:%d\n", stackSize);
#else


#if 1
    StuInfo stu1;
    StuInfo stu2;
    StuInfo stu3;
    memset(&stu1, 0, sizeof(stu1));
    memset(&stu2, 0, sizeof(stu2));
    memset(&stu3, 0, sizeof(stu3));

    /* 模块化初始化 */
    {
        stu1.age = 10;
        stu1.sex = 'm';
    }
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

    /* 插入 */
    StuInfo buffer[DEFAULT_NUM] = {stu1, stu2, stu3};
    for (int idx = 0; idx < DEFAULT_NUM; idx++)
    {
        arrayStackPush(&Stack, (void *)&buffer[idx]);
    }

    int stackSize = 0;
    arrayStackGetSize(&Stack, &stackSize);
    printf("arraySize:%d\n", stackSize);


    StuInfo *stackTopVal = NULL;
    while (arrayStackGetSize(&Stack, &stackSize))
    {
        arrayStackTop(&Stack, (void *)&stackTopVal);
        printf("stack top age:%d\t sex:%c\n", stackTopVal->age, stackTopVal->sex);
        arrayStackPop(&Stack);
    }
#endif
    arrayStackDestory(&Stack);
    return 0;
}