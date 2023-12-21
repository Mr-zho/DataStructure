#ifndef __BINARY_SEARCH_TREE_H_
#define __BINARY_SEARCH_TREE_H_
#include <stdio.h>

#define ELEMENTTYPE void*

/* 树的结点 (保留之前二叉搜索树结点结构体) */
typedef struct BSTreeNode
{
    ELEMENTTYPE val;
    struct BSTreeNode * left;
    struct BSTreeNode * right;
    struct BSTreeNode * parent;
} BSTreeNode;

/* 树的结点 */
typedef struct AVLTreeNode
{
    ELEMENTTYPE val;
    /* AVL树维护了一个高度的属性, 用于计算当前结点的平衡因子 */
    int height;     
    struct AVLTreeNode * left;
    struct AVLTreeNode * right;
    struct AVLTreeNode * parent;
} AVLTreeNode;

typedef struct BinarySearchTree
{
    int size;       /* 结点的个数 */
    int height;     /* 树的高度 */

    /* 钩子🪝函数放在树内部 */
    int (*compareFunc)(ELEMENTTYPE, ELEMENTTYPE);
    AVLTreeNode * root;
} BinarySearchTree;

/* 将二叉搜索树的结点 重命名为平衡二叉搜索树的结点 */
typedef BinarySearchTree BalanceBinarySearchTree;

/* 二叉搜索树初始化 */
int BalanceBinarySearchTreeInit(BalanceBinarySearchTree **pBSTree, int (*compareFunc)(ELEMENTTYPE, ELEMENTTYPE));

/* 二叉搜索树新增元素 */
int BalanceBinarySearchTreeInsert(BalanceBinarySearchTree *pBSTree, ELEMENTTYPE val);

/* 二叉搜索树删除元素 */
int BalanceBinarySearchTreeRemove(BalanceBinarySearchTree *pBSTree, ELEMENTTYPE val);

/* 二叉搜索树中是否包含指定元素 */
int BalanceBinarySearchTreeIsContainVal(BalanceBinarySearchTree *pBSTree, ELEMENTTYPE val);

/* 二叉搜索树是否为空树 */
int BalanceBinarySearchTreeIsNull(BalanceBinarySearchTree *pBSTree);

/* 二叉搜索树元素的个数 */
int BalanceBinarySearchTreeGetSize(BalanceBinarySearchTree *pBSTree, int *pSize);

/* 前序遍历 */
int BalanceBinarySearchTreePreOrderTravel(BalanceBinarySearchTree *pBSTree, int (*printFunc)(void *));

/* 中序遍历 */
int BalanceBinarySearchTreeInOrderTravel(BalanceBinarySearchTree *pBSTree, int (*printFunc)(void *));

/* 后序遍历 */
int BalanceBinarySearchTreePostOrderTravel(BalanceBinarySearchTree *pBSTree, int (*printFunc)(void *));

/* 层序遍历 */
int BalanceBinarySearchTreeLevelOrderTravel(BalanceBinarySearchTree *pBSTree, int (*printFunc)(void *));

/* 获取树的高度 */
int BalanceBinarySearchTreeGetHeight(BalanceBinarySearchTree *pBSTree, int *pHeight);

/* 二叉树的打印器 */
int BalanceBinarySearchTreeFormatPrintOut(BalanceBinarySearchTree *pBSTree);

/* 判断树是否是完全二叉树 */
int BalanceBinarySearchTreeIsComplete(BalanceBinarySearchTree *pBSTree);

/* 二叉搜索树的销毁 */
int BalanceBinarySearchTreeDestroy(BalanceBinarySearchTree *pBSTree);

/* 二叉树的保存 */
int BalanceBinarySearchTreeSave2File(BalanceBinarySearchTree *pBSTree, const char *pathname);
#endif  // __BINARY_SEARCH_TREE_H_