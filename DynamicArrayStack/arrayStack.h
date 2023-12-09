#ifndef __ARRAYSTACK_H_
#define __ARRAYSTACK_H_
#include "dynamicArray.h"

/* 取动态数组的名字为栈 在栈里面不使用动态数组的命名 */
// extern struct DynamicArray;
typedef struct DynamicArray ArrayStack;

/* 栈的初始化 */
int arrayStackInit(ArrayStack * pStack);

/* 栈的插入数据 */
int arrayStackPush(ArrayStack * pStack, int val);

/* 栈的弹出数据 */
int arrayStackPop(ArrayStack * pStack);

/* 查看栈顶数据 */
int arrayStackTop(ArrayStack * pStack, int *pVal);

/* 获取栈的大小 */
int arrayStackGetSize(ArrayStack * pStack, int *pSize);

/* 栈的销毁 */
int arrayStackDestory(ArrayStack * pStack);

#endif  //__ARRAYSTACK_H_