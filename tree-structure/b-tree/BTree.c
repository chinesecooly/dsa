//
// Created by Administrator on 2023/10/22.
//

#include "BTree.h"

struct BTreeNode {
    void **dataList;
    BTreeNode **childList;
    int dataCount;
};