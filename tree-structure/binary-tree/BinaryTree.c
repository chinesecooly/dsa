//
// Created by Administrator on 2023/9/3.
//

#include "BinaryTree.h"

struct BinaryTreeNode {
    void *data;
    struct BinaryTreeNode *lNode;
    struct BinaryTreeNode *rNode;

    int (*compare)(void *, void *);
};

/**
 * 前序中序构造
 * @param preOrderList 前序序列
 * @param inOrderList 中序序列
 * @param compare 比较函数
 * @param ps 前序起始位置
 * @param pe 前序结束位置
 * @param is 中序起始位置
 * @param ie 中序结束位置
 * @return 二叉树
 */
BinaryTree
binaryTreePreInOrderConstructor(void **preOrderList, void **inOrderList, int (*compare)(void *, void *), int ps, int pe,
                                int is, int ie) {
    BinaryTreeNode *root = malloc(sizeof(BinaryTreeNode));
    root->data = *(preOrderList + ps);
    int lLen, rLen;
    for (int i = is; i <= ie; ++i) {
        if (compare(*(inOrderList + i), *(preOrderList + ps))) {
            lLen = i - is;
            rLen = ie - i;
            break;
        }
    }
    if (lLen) {
        root->lNode = binaryTreePreInOrderConstructor(preOrderList, inOrderList, compare, ps + 1, ps + lLen, is,
                                                      is + lLen - 1);
    } else {
        root->lNode = NULL;
    }
    if (rLen) {
        root->rNode = binaryTreePreInOrderConstructor(preOrderList, inOrderList, compare, pe - rLen + 1, pe,
                                                      ie - rLen + 1, ie);
    } else {
        root->rNode = NULL;
    }
    return root;
}

/**
 * 先序遍历
 * @param tree
 */
void preOrder(BinaryTree tree, LinkedQueue preOrderList) {
    if (tree != NULL) {
        linkedQueueEnQueue(preOrderList, tree->data);
        preOrder(tree->lNode, preOrderList);
        preOrder(tree->rNode, preOrderList);
    }
}

/**
 * 中序遍历
 * @param tree
 */
void inOrder(BinaryTree tree, LinkedQueue inOrderList) {
    if (tree != NULL) {
        inOrder(tree->lNode, inOrderList);
        linkedQueueEnQueue(inOrderList, tree->data);
        inOrder(tree->rNode, inOrderList);
    }
}

/**
 * 后序遍历
 * @param tree
 */
void postOrder(BinaryTree tree, LinkedQueue postOrderList) {
    if (tree != NULL) {
        postOrder(tree->lNode, postOrderList);
        postOrder(tree->rNode, postOrderList);
        linkedQueueEnQueue(postOrderList, tree->data);
    }
}

/**
 * 层序遍历
 * @param tree
 */
void levelOrder(BinaryTree tree, LinkedQueue levelOrderList) {
    LinkedQueue queue = linkedQueueConstructor();
    linkedQueueEnQueue(queue, tree);
    while (!linkedQueueIsEmpty(queue)) {
        BinaryTreeNode *node = linkedQueueDeQueue(queue);
        linkedQueueEnQueue(levelOrderList, node->data);
        if (node->lNode != NULL) {
            linkedQueueEnQueue(queue, node->lNode);
        }
        if (node->rNode != NULL) {
            linkedQueueEnQueue(queue, node->rNode);
        }
    }
}

