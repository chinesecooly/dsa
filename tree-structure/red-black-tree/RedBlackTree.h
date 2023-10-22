//
// Created by Administrator on 2023/9/11.
//

#ifndef DSA_REDBLACKTREE_H
#define DSA_REDBLACKTREE_H

#include "../../util/Util.h"

typedef struct RedBlackTreeNode RedBlackTreeNode, *RedBlackTree;

/**
 * 构造函数
 * @param elementList
 * @param size
 * @param compare
 * @return
 */
RedBlackTree redBlackTreeConstructor(void **elementList, int size, int (*compare)(void *, void *));

/**
 * 二叉排序树的插入
 * @param tree
 * @param element
 * @param compare
 * @return
 */
bool redBlackTreeInsert(RedBlackTree *tree, void *element, int (*compare)(void *, void *));

/**
 * 查找
 * @param tree
 * @param element
 * @param compare
 * @return
 */
RedBlackTreeNode *redBlackTreeSearch(RedBlackTree tree, void *element, int (*compare)(void *, void *));

/**
 * 删除元素
 * @param tree
 * @param element
 * @param compare
 * @return
 */
bool redBlackTreeDelete(RedBlackTree *tree, void *element, int (*compare)(void *, void *));

/**
 * 二叉树的深度
 * @param tree
 * @return
 */
int redBlackTreeDeep(RedBlackTree tree);

/**
 * 打印二叉树
 * @param tree
 * @param dataPrint
 */
void redBlackTreePrint(RedBlackTree tree, void (*dataPrint)(void *));

#endif //DSA_REDBLACKTREE_H
