//
// Created by Administrator on 2022/3/26.
//

#include "PTree.h"

struct PTNode {
    PTreeElemType data;
    int parent;
};

struct PTree{
    PTNode nodes[MAX_TREE_SIZE];
    int n;
};
