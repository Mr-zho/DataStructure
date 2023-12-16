#include "binarySearchTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <doublelinklistQueue.h>

#define true    1
#define false   0


/* 静态函数前置声明 */
/* 判断结点是否是度为2的结点 */
static int binarySearchTreeNodeHasTwoChildrens(BSTreeNode *node);
/* 判断结点是否是叶子结点 */
static int binarySearchTreeNodeIsLeaf(BSTreeNode *node);
/* 创建新的树结点 */
static Node *createBstTreeNode(ELEMENTTYPE val);
/* 结点比较函数, 配置不同的类型进行比较 */
static int nodeCompare(ELEMENTTYPE val1, ELEMENTTYPE val2);

/* 获取当前结点的前驱结点 */
static BSTreeNode * precursorNode(BSTreeNode *node);
/* 获取当前结点的后继结点 */
static BSTreeNode * successorNode(BSTreeNode *node);


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
    /* 递归结束的条件 */
    if (node == NULL)
    {
        return;
    }
    /* 左子树 根结点 右子树 */
    binarySearchTreeInOrder(node->left);
    printf("%d\n", node->val);
    binarySearchTreeInOrder(node->right);
    
    return;
}

/* 中序遍历 */
/* 访问顺序: 遍历左子树, 根结点, 前序遍历右子树 */
int binarySearchTreeInOrderTravel(BinarySearchTree *pBSTree)
{
    int ret = 0;
    binarySearchTreeInOrder(pBSTree->root);
    return ret;
}


static void binarySearchTreePostOrder(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    binarySearchTreePostOrder(node->left);
    binarySearchTreePostOrder(node->right);
    printf("%d\n", node->val);
}

/* 后序遍历 */
/* 访问顺序: 遍历左子树, 右子树, 根结点*/
int binarySearchTreePostOrderTravel(BinarySearchTree *pBSTree)
{
    int ret = 0;
    binarySearchTreePostOrder(pBSTree->root);
    return ret;
}

/* 层序遍历 */
int binarySearchTreeLevelOrderTravel(BinarySearchTree *pBSTree)
{
    int ret = 0;
    /* 算法: 使用队列 
        1. 将根结点入队
        2. 循环执行以下操作, 直到队列为空
            2.1 将队头结点(A)出队,并访问
            2.2 将(A)的左子节点入队
            2.3 将(A)的右子节点入队
    */
    doubleLinkListQueue * queue = NULL;
    doublelinklistQueueInit(&queue);
    
    /* 将根结点入队 */
    doublelinklistQueuePush(queue, pBSTree->root);
    /* 队列的大小 */
    int queueSize = 0;
    BSTreeNode * BstVal = NULL;
    /* 当队列不为空的时候 */
    while (doublelinklistQueueSize(queue, &queueSize))
    {
        doublelinklistQueueTop(queue, (void *)&BstVal);
        printf ("BstVal:%d\n", BstVal->val);
        doublelinklistQueuePop(queue);

        /* 当左子树存在的时候，将左子树添加到队列中 */
        if (BstVal->left != NULL)
        {
            doublelinklistQueuePush(queue, BstVal->left);
        }
        
        /* 当右子树存在的时候，将右子树添加到队列中 */
        if (BstVal->right != NULL)
        {
            doublelinklistQueuePush(queue, BstVal->right);
        }
    }
    return ret;
}

/* 获取树的高度 */
int binarySearchTreeGetHeight(BinarySearchTree *pBSTree, int *pHeight)
{
    int ret = 0;
    if (!pBSTree)
    {   
        return 0;
    }
    /* 树的高度 */
    int height = 0;
    if (pBSTree->size == 0)
    {
        return height;
    }

    doubleLinkListQueue * queue = NULL;
    doublelinklistQueueInit(&queue);
    
    /* 将根结点入队 */
    doublelinklistQueuePush(queue, pBSTree->root);
    /* 队列的大小 */
    int levelSize = 1;
    BSTreeNode * BstVal = NULL;

    int queueSize = 0;

    while (doublelinklistQueueSize(queue, &queueSize))
    {
        doublelinklistQueueTop(queue, (void *)&BstVal);
        doublelinklistQueuePop(queue);
        levelSize--;

        if (BstVal->left != NULL)
        {
            doublelinklistQueuePush(queue, BstVal->left);
        }

        if (BstVal->right != NULL)
        {
            doublelinklistQueuePush(queue, BstVal->right);
        }

        if (levelSize == 0)
        {
            doublelinklistQueueSize(queue, &levelSize);
            height++; 
        }
    }

    *pHeight = height;
    return ret;
}

/* 二叉树的打印器 */
int binarySearchTreeFormatPrintOut(BinarySearchTree *pBSTree)
{
    int ret = 0;

    return ret;
}

/* 判断结点是否是度为2的结点 */
static int binarySearchTreeNodeHasTwoChildrens(BSTreeNode *node)
{
    if (!node)
    {
        return false;
    }
#if 0
    if (node->left != NULL && node->right != NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
#else
    return node->left && node->right ? true : false;
#endif
}

/* 判断结点是否是叶子结点 */
int binarySearchTreeNodeIsLeaf(BSTreeNode *node)
{
    if (!node)
    {
        return false;
    }

    #if 0
    /* 左子树不为NULL && 右子树为NULL 或者 要么左子树为NULL && 右子树不为NULL */
    if ((node->left != NULL && node->right == NULL) || (node->left == NULL && node->right != NULL))
    {
        return true;
    }
    else
    {
        return false;
    }
    #else
    return (node->left != NULL && node->right == NULL) || (node->left == NULL && node->right != NULL) ? true : false;
    #endif
}


/* 获取当前结点的前驱结点 */
static BSTreeNode * precursorNode(BSTreeNode *node)
{
    return NULL;
}
/* 获取当前结点的后继结点 */
static BSTreeNode * successorNode(BSTreeNode *node)
{
    return NULL;
}

/* 根据传递的元素获取到指定搜索树结点 */
BSTreeNode * accordElementGetAppointNode(ELEMENTTYPE val)
{
    return NULL;
}

/* 判断树是否是完全二叉树 */
/* 算法: 
 *  1. 如果node.left != NULL && node.right != NULL. 将node.left和node.right入队
 *  2. 如果node.left == NULL && node.right == NULL. 那么返回false.
 *  3. 如果node.leaf != NULL && node.right == NULL. 或者 node.leaf == NULL && node.right == NULL
 *      那么后面遍历到的所有节点都应该是叶子结点，才是完全二叉树， 否则返回false.  
 * */
int binarySearchTreeIsComplete(BinarySearchTree *pBSTree)
{
    int ret = 0;
    
    /* 如果是空树 */
    #if 0
    if (pBSTree->root == NULL)
    {
        return false;
    }
    #else
    if (pBSTree->size == 0)
    {
        return false;
    }
    #endif

    /* 使用队列的方式来判断二叉树是否是完全二叉树 */
    doubleLinkListQueue *queue = NULL;
    doublelinklistQueueInit(&queue);
    /* 根结点入队 */
    doublelinklistQueuePush(queue, pBSTree->root);

    BSTreeNode * node = NULL;
    int leaf = false;       /* 叶子结点的标记 */
    while (!doublelinklistQueueIsEmpty(queue))
    {
        doublelinklistQueueTop(queue, (void *)&node);
        doublelinklistQueuePop(queue);
        if (leaf && !binarySearchTreeNodeIsLeaf(node))
        {
            return false;
        }

        if (node->left != NULL)
        {
            doublelinklistQueuePush(queue, node->left);
        } else if (node->right != NULL)
        {
            /* node->left == NULL && node->right != NULL */
            return false;
        }

        if (node->right != NULL)
        {
            doublelinklistQueuePush(queue, node->right);
        }
        else 
        {
            /* node->left == NULL && node->right == NULL */
            /* node->left != NULL && node->right == NULL */
            leaf = true;
        }
    }

    return true;
}