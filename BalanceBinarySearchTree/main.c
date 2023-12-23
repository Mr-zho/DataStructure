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

    BinarySearchTree *BST = NULL;
#if 1
    /* 初始化树 */
    balanceBinarySearchTreeInit(&BST, compareBasicType);

    int array1[] = {666, 555, 888, 444, 600, 777, 999, 333, 1111};
    for (int idx = 0; idx < sizeof(array1) / sizeof(array1[0]); idx++)
    {
        balanceBinarySearchTreeInsert(BST, (void *)&array1[idx]);
    }
#if 0
    int size = 0;
    BalanceBinarySearchTreeGetSize(BST, &size);
    printf("size:%d\n", size);

    /* 中序遍历 */
    printf("In order:\n");
    BalanceBinarySearchTreeInOrderTravel(BST, printBasicData);
    printf("\n");
    /* 获取树的高度 */
    int height = 0;
    BalanceBinarySearchTreeGetHeight(BST, &height);
    printf("height:%d\n", height);

    /* 层序遍历 */
    printf("Level order:\n");
    BalanceBinarySearchTreeLevelOrderTravel(BST, printBasicData);
    printf("\n");

    int goodElement = 789;
    BalanceBinarySearchTreeRemove(BST, &goodElement);

    int ret = BalanceBinarySearchTreeIsContainVal(BST, &goodElement);
    printf("ret:%d\n", ret);


    size = 0;
    BalanceBinarySearchTreeGetSize(BST, &size);
    printf("size:%d\n", size);
#endif

#if 0
    /* 中序遍历 */
    printf("In order:\n");
    binarySearchTreeInOrderTravel(BST, printBasicData);
    printf("\n");
#endif

#if 0
    /* 层序遍历 */
    printf("Level order:\n");
    BalanceBinarySearchTreeLevelOrderTravel(BST, printBasicData);
    printf("\n");
#endif

#if 0
    int badElement = 56;
    ret = binarySearchTreeIsContainVal(BST, &badElement);
    printf("ret:%d\n", ret);
#endif

    /* 销毁二叉搜索树 -> 检测内存泄漏 */
    balanceBinarySearchTreeDestroy(BST);
#else
    /* 初始化树 */
    binarySearchTreeInit(&BST, compareSelfStruct);
    
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
        binarySearchTreeInsert(BST, (void *)&buffer[idx]);
    }
    binarySearchTreePreOrderTravel(BST);
#endif
    return 0;
}