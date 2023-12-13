#include "binarySearchTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* 二叉搜索树初始化 */
int binarySearchTreeInit(BinarySearchTree **pBSTree)
{
    int ret = 0;
    if (pBSTree == NULL)
    {
        return -1;
    }

    BinarySearchTree * pBst = (BinarySearchTree*)malloc(sizeof(BinarySearchTree) * 1);
    if (pBst == NULL)
    {
        return -1;
    }
    memset(pBst, 0, sizeof(BinarySearchTree));
    
    pBst->root = (Node *)malloc(sizeof(Node) * 1);
    if (!(pBst->root))
    {
        return -1;
    }
    memset(pBst->root, 0, sizeof(Node));
    /* 初始化树的结点为0 */
    {    
        pBst->size = 0;
    }

    /* 初始化树的根结点 */
    {
        pBst->root->left = NULL;
        pBst->root->right = NULL;
        pBst->root->parent = NULL;
        pBst->root->val = 0;
    }

    *pBSTree = pBst;
    return ret;
}

/* 结点比较函数, 配置不同的类型进行比较 */
/* todo... 后面把它做成包装器 */
static int nodeCompare(ELEMENTTYPE val1, ELEMENTTYPE val2)
{
    return val1 - val2;
}

/* 创建新的结点 */
static Node *createBstTreeNode(ELEMENTTYPE val)
{
    Node *newNode = (Node*)malloc(sizeof(Node) * 1);
    if (newNode == NULL)
    {
        return NULL;
    }
    memset(newNode, 0, sizeof(Node) * 1);
    {
        /* 开辟的新结点赋值 */
        newNode->val = val;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->parent = NULL;
    }
    return newNode;
}
/* 二叉搜索树新增元素 */
int binarySearchTreeInsert(BinarySearchTree *pBSTree, ELEMENTTYPE val)
{
    int ret = 0;
    /* 空树 */
    if (pBSTree->size == 0)
    {
        pBSTree->root->val = val;
        /* 树的结点加一 */
        ++(pBSTree->size);
        return ret;
    }

    Node *parentNode = pBSTree->root;
    Node *travelNode = pBSTree->root;
    
    int cmp = 0;
    while (travelNode != NULL)
    {
        parentNode = travelNode;
        cmp = nodeCompare(val, travelNode->val);
        if (cmp < 0)
        {
            travelNode = travelNode->left;
        }
        else if (cmp > 0)
        {
            travelNode = travelNode->right;
        }
        else
        {
            return ret;
        }
    }

    /* 新增树结点并赋值 */
    Node * newNode = createBstTreeNode(val);
    if (newNode == NULL)
    {
        /* todo... */
        return ret;
    }

    if (cmp < 0)
    {
        /* 新结点插入到左子树 */
        parentNode->left = newNode;
    }
    else
    {
        /* 新结点插入到左子树 */
        parentNode->right = newNode;
    }
    pBSTree->size++;
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

static void binarySearchTreePreOrder(Node *node)
{   
    /* 递归结束的条件 */
    if (node == NULL)
    {
        return;
    }
    /* 根结点 左子树 右子树 */
    printf("%d\n", node->val);
    binarySearchTreePreOrder(node->left);
    binarySearchTreePreOrder(node->right);
}

/* 前序遍历 */
/* 访问顺序: 根结点, 前序遍历左子树, 前序遍历右子树 */
int binarySearchTreePreOrderTravel(BinarySearchTree *pBSTree)
{
    int ret = 0;
    if (pBSTree == NULL)
    {
        return ret;
    }
    binarySearchTreePreOrder(pBSTree->root);
    return ret;
}

static void binarySearchTreeInOrder(Node *node)
{

}

/* 中序遍历 */
/* 访问顺序: 遍历左子树, 根结点, 前序遍历右子树 */
int binarySearchTreeInOrderTravel(BinarySearchTree *pBSTree)
{
    int ret = 0;

    return ret;
}


static void binarySearchTreePostOrder(Node *node)
{
    
}

/* 后序遍历 */
int binarySearchTreePostOrderTravel(BinarySearchTree *pBSTree)
{
    int ret = 0;

    return ret;
}

/* 层序遍历 */
int binarySearchTreeLevelOrderTravel(BinarySearchTree *pBSTree)
{
    int ret = 0;

    return ret;
}