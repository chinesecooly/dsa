//
// Created by Administrator on 2023/9/8.
//

#include "ChildTree.h"

struct ChildTreeNode {
    void *data;
    int index; //表示当前接结点在数组中的位置，仅在链表中使用
    struct ChildTreeNode *child;
};

struct ChildTree {
    struct ChildTreeNode *nodeList;
    int size;
    int nodeCount;
};

