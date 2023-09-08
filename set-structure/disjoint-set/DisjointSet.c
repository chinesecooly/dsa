//
// Created by Administrator on 2023/9/8.
//

#include "DisjointSet.h"


struct DisjointSetNode {
    void *data;
    int parent;
};

struct DisjointSet {
    struct DisjointSetNode *nodeList;
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
DisjointSet disjointSetConstructor(int size, int (*compare)(void *, void *)) {
    DisjointSet set = malloc(sizeof(struct DisjointSet));
    set->nodeList = calloc(size, sizeof(struct DisjointSetNode));
    set->size = size;
    set->nodeCount = 0;
    set->compare = compare;
    return set;
}

/**
 * 查找元素位置
 * @param set
 * @param element
 * @return
 */
static int disjointSetIndexOf(DisjointSet set, void *element) {
    if (set->size == 0 || set->nodeCount == 0 || element == NULL) {
        return -1;
    }
    struct DisjointSetNode *node = set->nodeList;
    for (int i = 0; i < set->size; ++i) {
        if (set->compare(node + i, element) == 0) {
            return i;
        }
    }
    return -1;
}

/**
 * 插入元素
 * @param set
 * @param element
 * @return
 */
bool disjointSetInsert(DisjointSet set, void *element) {
    if (set->nodeCount == set->size) {
        return false;
    }
    (set->nodeList + set->nodeCount)->data = element;
    (set->nodeList + set->nodeCount)->parent = -1;
    return true;
}

/**
 * 查找元素所在集合
 * @param set
 * @param element
 * @return
 */
void *disjointSetFind(DisjointSet set, void *element) {
    int index = disjointSetIndexOf(set, element);
    if (index == -1) {
        return NULL;
    }
    struct DisjointSetNode *node = set->nodeList + index;
    while (node->parent >= 0) {
        node = set->nodeList + node->parent;
    }
    return node->data;
}

/**
 * 合并集合
 * @param set
 * @param element1
 * @param element2
 * @return
 */
bool disjointSetUnion(DisjointSet set, void *element1, void *element2) {
    int index1 = disjointSetIndexOf(set, disjointSetFind(set, element1));
    int index2 = disjointSetIndexOf(set, disjointSetFind(set, element2));
    if (index1 == -1 || index2 == -1) {
        return false;
    }
    if (abs((set->nodeList + index1)->parent) >= abs((set->nodeList + index2)->parent)) {
        (set->nodeList + index1)->parent += (set->nodeList + index2)->parent;
        (set->nodeList + index2)->parent = index1;
    } else {
        (set->nodeList + index2)->parent += (set->nodeList + index1)->parent;
        (set->nodeList + index1)->parent = index2;
    }
    return true;
}

