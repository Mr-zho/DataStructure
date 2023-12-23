#include "balanceBinarySearchTree.h"
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE     32
#define DEFAULT_SIZE    3

typedef struct StuInfo
{
    int age;
    char sex;
    char name[BUFFER_SIZE];
} StuInfo; // 28字节


int compareSelfStruct(ELEMENTTYPE arg1, ELEMENTTYPE arg2)
{
    StuInfo info1 = *(StuInfo *)arg1;
    StuInfo info2 = *(StuInfo *)arg2;

    #if 0
    /* 以年龄来比较大小 */
    return info1.age - info2.age;
    #elif 1
    /* 以姓名来比较大小 */
    return strcmp(info1.name, info2.name);
    #endif 
}   


int printBasicData(void *arg)
{
    int data = *(int *)arg;
    printf("data:%d\t", data);
}

int compareBasicType(ELEMENTTYPE arg1, ELEMENTTYPE arg2)
{
    int va11 = *(int *)arg1;
    int va12 = *(int *)arg2;

    return va11 - va12;
}

int main()
{

    BinarySearchTree *AVL = NULL;
#if 1
    /* 初始化树 */
    balanceBinarySearchTreeInit(&AVL, compareBasicType);

    /* LL情况 - 右旋 */
    // int array1[] = {555, 444, 333};
    /* RR情况 - 左旋 */
    // int array1[] = {555, 666, 777};

    /* LR情况 - */
    int array1[] = {555, 333, 444};

    /* RL情况 - */
    // int array1[] = {333, 555, 444};

    for (int idx = 0; idx < sizeof(array1) / sizeof(array1[0]); idx++)
    {
        balanceBinarySearchTreeInsert(AVL, (void *)&array1[idx]);
    }
#if 1
    int size = 0;
    balanceBinarySearchTreeGetSize(AVL, &size);
    printf("size:%d\n", size);

/* 获取树的高度 */
    int height = 0;
    balanceBinarySearchTreeGetHeight(AVL, &height);
    printf("height:%d\n", height);
#endif

#if 1
    /* 层序遍历 */
    printf("Level order:\n");
    balanceBinarySearchTreeLevelOrderTravel(AVL, printBasicData);
    printf("\n");
#endif

#if 0
    /* 中序遍历 */
    printf("In order:\n");
    BalanceBinarySearchTreeInOrderTravel(AVL, printBasicData);
    printf("\n");
    

    /* 层序遍历 */
    printf("Level order:\n");
    BalanceBinarySearchTreeLevelOrderTravel(AVL, printBasicData);
    printf("\n");

    int goodElement = 789;
    BalanceBinarySearchTreeRemove(AVL, &goodElement);

    int ret = BalanceBinarySearchTreeIsContainVal(AVL, &goodElement);
    printf("ret:%d\n", ret);


    size = 0;
    BalanceBinarySearchTreeGetSize(AVL, &size);
    printf("size:%d\n", size);
#endif

#if 0
    /* 中序遍历 */
    printf("In order:\n");
    binarySearchTreeInOrderTravel(AVL, printBasicData);
    printf("\n");
#endif

#if 0
    /* 层序遍历 */
    printf("Level order:\n");
    BalanceBinarySearchTreeLevelOrderTravel(AVL, printBasicData);
    printf("\n");
#endif

#if 0
    int badElement = 56;
    ret = binarySearchTreeIsContainVal(AVL, &badElement);
    printf("ret:%d\n", ret);
#endif

    /* 销毁二叉搜索树 -> 检测内存泄漏 */
    balanceBinarySearchTreeDestroy(AVL);
#else
    /* 初始化树 */
    binarySearchTreeInit(&AVL, compareSelfStruct);
    
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
        char *name = "yuchen";
        strncpy(stu1.name, name, sizeof(stu1.name) - 1);
    }
    {
        stu2.age = 20;
        stu2.sex = 'f';
        char *name = "mr_shuo";
        strncpy(stu2.name, name, sizeof(stu2.name) - 1);
    }
    /* 模块化初始化 */
    {
        stu3.age = 30;
        stu3.sex = 'm';
        char *name = "mr_yu";
        strncpy(stu3.name, name, sizeof(stu3.name) - 1);
    }

    /* 插入数据 */
    StuInfo buffer[DEFAULT_SIZE] = {stu1, stu2, stu3};

    for (int idx = 0; idx < DEFAULT_SIZE; idx++)
    {   
        binarySearchTreeInsert(AVL, (void *)&buffer[idx]);
    }
    binarySearchTreePreOrderTravel(AVL);
#endif
    return 0;
}