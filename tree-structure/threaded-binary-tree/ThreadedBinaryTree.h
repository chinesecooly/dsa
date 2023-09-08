//
// Created by Administrator on 2023/9/3.
//

#ifndef DSA_THREADEDBINARYTREE_H
#define DSA_THREADEDBINARYTREE_H

#include "../../util/Util.h"

typedef struct ThreadedBinaryTreeNode ThreadedBinaryTreeNode, *ThreadedBinaryTree;

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
ThreadedBinaryTree threadedBinaryTreePreInOrderConstructor(void **preOrderList, void **inOrderList, int (*compare)(void *, void *), int ps, int pe, int is, int ie);

#endif //DSA_THREADEDBINARYTREE_H
