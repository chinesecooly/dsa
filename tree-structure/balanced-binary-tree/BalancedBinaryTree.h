//
// Created by Administrator on 2023/9/11.
//

#ifndef DSA_BALANCEDBINARYTREE_H
#define DSA_BALANCEDBINARYTREE_H

#include "../../util/Util.h"

typedef struct BalancedBinaryTreeNode BalancedBinaryTreeNode, *BalancedBinaryTree;

/**
 * 平衡二叉树树构造函数
 * @param elementList 元素列表
 * @param size 列表大小
 * @param compare 元素比较函数
 * @return
 */
BalancedBinaryTree balancedBinaryTreeConstructor(void **elementList, int size, int (*compare)(void *, void *));

/**
 * 插入
 * @param tree
 * @param element
 * @param compare
 * @return
 */
bool balancedBinaryTreeInsert(BalancedBinaryTree *tree, void *element, int (*compare)(void *, void *));

/**
 * 查找
 * @param tree
 * @param element
 * @param compare
 * @return
 */
BalancedBinaryTreeNode *balancedBinaryTreeSearch(BalancedBinaryTree tree, void *element, int (*compare)(void *, void *));

/**
 * 删除
 * @param tree
 * @param element
 * @param compare
 * @return
 */
bool balancedBinaryTreeDelete(BalancedBinaryTree *tree, void *element, int (*compare)(void *, void *));

/**
 * 二叉树的深度
 * @param tree
 * @return
 */
int balancedBinaryTreeDeep(BalancedBinaryTree tree);

/**
 * 打印二叉树
 * @param tree
 * @param dataPrint
 */
void balancedBinaryTreePrint(BalancedBinaryTree tree, void (*dataPrint)(void *));

#endif //DSA_BALANCEDBINARYTREE_H
