#include "binarySearchTree.h"


int main()
{
    BinarySearchTree *BST = NULL;
    /* 初始化树 */
    binarySearchTreeInit(&BST);

    /* 插入数据 */
    binarySearchTreeInsert(BST, 3);
    binarySearchTreeInsert(BST, 1);
    binarySearchTreeInsert(BST, 7);

    binarySearchTreePreOrderTravel(BST);

    return 0;
}