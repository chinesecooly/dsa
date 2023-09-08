//
// Created by Administrator on 2023/9/8.
//

#include "ParentTree.h"


struct ParentTreeNode {
    void *data;
    int parent;
};

struct ParentTree {
    struct ParentTreeNode *nodeList;
    int size;
    int nodeCount;

    int (*compare)(void *, void *);
};

/**
 * 构造函数
 * @param size
 * @param compare
 * @return
 */
ParentTree parentTreeConstructor(int size, int (*compare)(void *, void *)) {
    ParentTree tree = malloc(sizeof(struct ParentTree));
    tree->nodeList = calloc(size, sizeof(struct ParentTreeNode));
    tree->size = size;
    tree->nodeCount = 0;
    tree->compare = compare;
    return tree;
}

/**
 * 插入元素
 * @param tree
 * @param parent
 * @param element
 * @return
 */
bool parentTreeInsert(ParentTree tree, void *parent, void *element) {
    if (tree->nodeCount == tree->size) {
        return false;
    }
    struct ParentTreeNode node = *(tree->nodeList + tree->nodeCount - 1);
    node.data = element;
    node.parent = parentTreeIndexOf(tree, parent);
    tree->nodeCount++;
    return true;
}

/**
 * 删除操作
 * @param tree
 * @param element
 * @return
 */
bool parentTreeDelete(ParentTree tree, void *element) {
    int index = -1;
    struct ParentTreeNode *node = tree->nodeList;
    for (int i = 0; i < tree->size; ++i) {
        if (tree->compare((node + i)->data, element) == 0) {
            //找到之后用最后一个元素替换
            *(node + i) = *(node + tree->nodeCount - 1);
            tree->nodeCount--;
            index = i;
        }
    }
    if (index == -1) {
        return false;
    }
    //查找删除元素的子节点，全部删除
    for (int i = 0; i < tree->size; ++i) {
        if ((node + i)->parent == index) {
            parentTreeDelete(tree, node + i);
        }
    }
    return true;
}

/**
 * 查找元素位置
 * @param tree
 * @param element
 * @return
 */
int parentTreeIndexOf(ParentTree tree, void *element) {
    if (tree->size == 0 || tree->nodeCount == 0) {
        return -1;
    }
    struct ParentTreeNode *node = tree->nodeList;
    for (int i = 0; i < tree->size; ++i) {
        if (tree->compare(node + i, element) == 0) {
            return i;
        }
    }
    return -1;
}

