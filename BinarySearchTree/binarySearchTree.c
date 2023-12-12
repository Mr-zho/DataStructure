#include "binarySearchTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* 二叉搜索树初始化 */
int binarySearchTreeInit(BinarySearchTree *pBSTree)
{
    int ret = 0;

    return ret;
}

/* 二叉搜索树新增元素 */
int binarySearchTreeInsert(BinarySearchTree *pBSTree, ELEMENTTYPE val)
{
    int ret = 0;
    /* 空树 */
    if (pBSTree->size == 0)
    {
        pBSTree->root->val = val;
        return ret;
    }

    Node *travelNode = pBSTree->root;
    
    while (travelNode != NULL)
    {
        if (val < travelNode->val)
        {
            travelNode = travelNode->left;
        }
        else if (val > travelNode->val)
        {
            travelNode = travelNode->right;
        }
        else
        {
            return ret;
        }
    }
    return ret;
}

/* 二叉搜索树删除元素 */
int binarySearchTreeRemove(BinarySearchTree *pBSTree, ELEMENTTYPE val)
{
    int ret = 0;

    return ret;
}

/* 二叉搜索树中是否包含指定元素 */
int binarySearchTreeIsContainVal(BinarySearchTree *pBSTree, ELEMENTTYPE val)
{
    int ret = 0;

    return ret;
}

/* 二叉搜索树是否为空树 */
int binarySearchTreeIsNull(BinarySearchTree *pBSTree)
{
    if (pBSTree == NULL)
    {
        return 1;
    }
    return (pBSTree->size == 0) ? 1 : 0;
}

/* 二叉搜索树元素的个数 */
int binarySearchTreeGetSize(BinarySearchTree *pBSTree)
{
    if (!pBSTree)
    {
        return 0;
    }
    return pBSTree->size;
}