//
// Created by Administrator on 2023/9/3.
//

#include "HuffmanTree.h"

typedef struct HuffmanTreeNode {
    void *data;
    void *weight;
    struct HuffmanTreeNode *lNode;
    struct HuffmanTreeNode *rNode;
} HuffmanTreeNode;

static void sort(HuffmanTreeNode **forest, int size, int (*reCompare)(void *, void *)) {
    //todo
}

/**
 * 构造哈夫曼树
 * @param dataList 数据列表
 * @param weightList 权值列表
 * @param size 大小
 * @param reCompare 权值逆序比较
 * @param weightSum 权值相加
 * @return
 */
HuffmanTree huffmanTreeNodeConstructor(void *dataList[], void *weightList[], int size, int (*reCompare)(void *, void *), void *(*weightSum)(void *, void *)) {
    HuffmanTreeNode *forest[size];
    int treeCount = 0;
    for (int i = 0; i < size; ++i) {
        HuffmanTreeNode *node = malloc(sizeof(HuffmanTreeNode));
        node->data = dataList[i];
        node->weight = weightList[i];
        node->lNode = NULL;
        node->rNode = NULL;
        forest[i] = node;
        treeCount++;
    }
    sort(forest, size, reCompare);
    for (; treeCount != 1;) {
        HuffmanTreeNode *node = malloc(sizeof(HuffmanTreeNode));
        node->lNode = forest[0];
        forest[0] = NULL;
        treeCount--;
        node->rNode = forest[1];
        forest[1] = NULL;
        treeCount--;
        node->data = NULL;
        node->weight = weightSum(node->lNode->weight, node->rNode->weight);
        forest[0] = node;
        sort(forest, size, reCompare);
    }
    return forest[0];
}

/**
 * 是否是叶子结点
 * @param node
 * @return
 */
static bool isLeafNode(HuffmanTreeNode *node) {
    return node->lNode == NULL && node->rNode == NULL;
}

/**
 * 哈夫曼编码
 * @param tree
 * @param target
 * @param compare
 * @return
 */
char *huffmanCoding(HuffmanTree tree, void *target, int (*compare)(void *, void *)) {
    if (tree != NULL) {
        char *lr = huffmanCoding(tree->lNode, target, compare);
        char *rr = huffmanCoding(tree->rNode, target, compare);
        if (lr != NULL) {
            char *code = calloc(strlen(lr) + 2, sizeof(char));
            strcat(code, "0");
            strcat(code, lr);
            return code;
        } else if (rr != NULL) {
            char *code = calloc(strlen(rr) + 2, sizeof(char));
            strcat(code, "1");
            strcat(code, rr);
            return code;
        } else if (tree->lNode != NULL && isLeafNode(tree->lNode) && compare(tree->lNode->data, target) == 0) {
            return "0";
        } else if (tree->rNode != NULL && isLeafNode(tree->rNode) && compare(tree->rNode->data, target) == 0) {
            return "1";
        } else {
            return NULL;
        }
    } else {
        return NULL;
    }
}

/**
 * 先序遍历
 * @param tree
 */
void huffmanTreePreOrder(HuffmanTree tree, LinkedQueue preOrderList) {
    if (tree != NULL) {
        linkedQueueEnQueue(preOrderList, tree->weight);
        huffmanTreePreOrder(tree->lNode, preOrderList);
        huffmanTreePreOrder(tree->rNode, preOrderList);
    }
}


