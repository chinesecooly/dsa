//
// Created by Administrator on 2023/9/3.
//

#include "HuffmanTree.h"

struct HuffmanTreeNode {
    void *data;
    void *weight;
    struct HuffmanTreeNode *lNode;
    struct HuffmanTreeNode *rNode;
};


