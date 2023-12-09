#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "arrayStack.h"

#define DEFAULT_NUM    2

int main(int argc, const char *argv[])
{
    ArrayStack Stack;
    arrayStackInit(&Stack);

    for (int idx = 1; idx <= (DEFAULT_NUM << 1); idx++)
    {
        arrayStackPush(&Stack, idx);
    }
    int stackSize = 0;
    arrayStackGetSize(&Stack, &stackSize);
    printf("stack size:%d\n", stackSize);

    int stackTopVal = 0;
    while (arrayStackGetSize(&Stack, &stackSize))
    {
        arrayStackTop(&Stack, &stackTopVal);
        printf("stack top:%d\n", stackTopVal);
        arrayStackPop(&Stack);
    }
    arrayStackGetSize(&Stack, &stackSize);
    printf("stack size:%d\n", stackSize);

    arrayStackDestory(&Stack);
    return 0;
}