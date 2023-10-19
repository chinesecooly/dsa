//
// Created by Administrator on 2023/9/3.
//

#include "ThreadedBinaryTree.h"

struct ThreadedBinaryTreeNode {
    void *data;
    ThreadedBinaryTreeNode *lNode;
    ThreadedBinaryTreeNode *rNode;
    ThreadedBinaryTreeNode *pNode;
    bool lIsPredecessor;
    bool rIsSuccessor;
};

/**
 * 先序中序构造二叉树
 * @param preOrderList
 * @param inOrderList
 * @param compare
 * @param ps
 * @param pe
 * @param is
 * @param ie
 * @return
 */
ThreadedBinaryTree preInOrderConstructor(void **preOrderList, void **inOrderList, int (*compare)(void *, void *), int ps, int pe, int is, int ie) {
    ThreadedBinaryTreeNode *root = malloc(sizeof(ThreadedBinaryTreeNode));
    root->data = *(preOrderList + ps);
    root->lIsPredecessor = false;
    root->rIsSuccessor = false;
    int lLen, rLen;
    for (int i = is; i <= ie; ++i) {
        if (compare(*(inOrderList + i), *(preOrderList + ps))) {
            lLen = i - is;
            rLen = ie - i;
            break;
        }
    }
    if (lLen) {
        root->lNode = preInOrderConstructor(preOrderList, inOrderList, compare, ps + 1, ps + lLen, is, is + lLen - 1);
    } else {
        root->lNode = NULL;
    }
    if (rLen) {
        root->lNode = preInOrderConstructor(preOrderList, inOrderList, compare, pe - rLen + 1, pe, ie - rLen + 1, ie);
    } else {
        root->rNode = NULL;
    }
    return root;
}

/**
 * 先序线索化
 * @param tree
 * @param predecessor
 * @return
 */
ThreadedBinaryTree preOrderThreaded(ThreadedBinaryTree tree, ThreadedBinaryTreeNode *predecessor) {
    if (tree != NULL) {
        if (tree->lNode == NULL) {
            tree->lNode = predecessor;
            tree->lIsPredecessor = true;
        }
        if (predecessor != NULL && predecessor->rNode == NULL) {
            predecessor->rNode = tree;
            predecessor->rIsSuccessor = true;
        }
        predecessor = tree;
        if (tree->lIsPredecessor == false) {
            preOrderThreaded(tree->lNode, predecessor);
        }
        if (tree->rIsSuccessor == false) {
            preOrderThreaded(tree->rNode, predecessor);
        }
    }
}

/**
 * 先序中序构造线索二叉树
 * @param preOrderList
 * @param inOrderList
 * @param compare
 * @param ps
 * @param pe
 * @param is
 * @param ie
 * @return
 */
ThreadedBinaryTree threadedBinaryTreePreInOrderConstructor(void **preOrderList, void **inOrderList, int (*compare)(void *, void *), int ps, int pe, int is, int ie) {
    ThreadedBinaryTree tree = preInOrderConstructor(preOrderList, inOrderList, compare, ps, pe, is, ie);
    ThreadedBinaryTreeNode *pre = NULL;
    preOrderThreaded(tree, pre);
    if (pre->rNode == NULL) {
        pre->rIsSuccessor = tree;
    }
    return tree;
}

/**
 * 寻找前序序列的前驱
 * @param tree
 * @return
 */
ThreadedBinaryTreeNode *preOrderFirstNode(ThreadedBinaryTree tree) {
    if (tree->lIsPredecessor == true) {
        return tree->lNode;
    } else {
        ThreadedBinaryTreeNode *parent = tree->pNode;
        if (parent->lNode == tree) {
            return parent;
        } else {
            if (parent->lIsPredecessor == true || parent->lNode == NULL) {
                return parent;
            } else {
                ThreadedBinaryTreeNode *node = parent->lNode;
                while (node != NULL) {
                    if (node->rNode == tree) {
                        break;
                    } else if (node->rNode != NULL) {
                        node = node->rNode;
                    } else if (node->lIsPredecessor == false && node->lNode != NULL) {
                        node = node->lNode;
                    }
                }
                return node;
            }
        }
    }
}

/**
 * 寻找前序序列的后继
 * @param tree
 * @return
 */
ThreadedBinaryTreeNode *preOrderNextNode(ThreadedBinaryTree tree) {
    if (tree->rIsSuccessor == true) {
        return tree->rNode;
    } else {
        if (tree->lIsPredecessor == false && tree->lNode != NULL) {
            return tree->lNode;
        } else {
            return tree->rNode;
        }
    }
}

/**
 * 线索二叉树前序遍历
 * @param tree
 * @param queue
 */
void threadedBinaryTreePreOrder(ThreadedBinaryTree tree, LinkedQueue queue) {
    for (ThreadedBinaryTreeNode *node = tree; node != NULL; node = preOrderNextNode(node)) {
        linkedQueueEnQueue(queue, node->data);
    }
}

