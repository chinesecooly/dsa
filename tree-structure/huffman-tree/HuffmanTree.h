//
// Created by Administrator on 2023/9/3.
//

#ifndef DSA_HUFFMANTREE_H
#define DSA_HUFFMANTREE_H

#include "../../util/Util.h"
#include "../../linear-structure/queue/linked-queue/LinkedQueue.h"

typedef struct HuffmanTreeNode *HuffmanTree;

/**
 * 构造哈夫曼树
 * @param dataList 数据列表
 * @param weightList 权值列表
 * @param size 大小
 * @param reCompare 权值逆序比较
 * @param weightSum 权值相加
 * @return
 */
HuffmanTree huffmanTreeNodeConstructor(void *dataList[], void *weightList[], int size, int (*reCompare)(void *, void *), void *(*weightSum)(void *, void *));


/**
 * 哈夫曼编码
 * @param tree
 * @param target
 * @param compare
 * @return
 */
char *huffmanCoding(HuffmanTree tree, void *target, int (*compare)(void *, void *));

/**
 * 先序遍历
 * @param tree
 */
void huffmanTreePreOrder(HuffmanTree tree, LinkedQueue preOrderList);

#endif //DSA_HUFFMANTREE_H
