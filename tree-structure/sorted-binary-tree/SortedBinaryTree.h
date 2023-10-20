//
// Created by Administrator on 2023/9/10.
//

#ifndef DSA_SORTEDBINARYTREE_H
#define DSA_SORTEDBINARYTREE_H

#include "../../util/Util.h"

typedef struct SortedBinaryTreeNode SortedBinaryTreeNode, *SortedBinaryTree;

/**
 * 二叉排序树构造函数
 * @param elementList
 * @param size
 * @param compare
 * @return
 */
SortedBinaryTree sortedBinaryTreeConstructor(void **elementList, int size, int (*compare)(void *, void *));

/**
 * 二叉排序树的查找
 * @param tree
 * @param element
 * @param compare
 * @return
 */
SortedBinaryTreeNode *sortedBinaryTreeSearch(SortedBinaryTree tree, void *element, int (*compare)(void *, void *));

/**
 * 二叉排序树的插入
 * @param tree
 * @param element
 * @param compare
 * @return
 */
bool sortedBinaryTreeInsert(SortedBinaryTree *tree, void *element, int (*compare)(void *, void *));

/**
 * 删除元素
 * @param tree
 * @param element
 * @param compare
 * @return
 */
bool sortedBinaryTreeDelete(SortedBinaryTree *tree, void *element, int (*compare)(void *, void *));

/**
 * 打印二叉树
 * @param tree
 */
void printSortedBinaryTree(SortedBinaryTree tree);

#endif //DSA_SORTEDBINARYTREE_H
