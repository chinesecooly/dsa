//
// Created by Administrator on 2023/9/8.
//

#include "ChildSiblingTree.h"

struct ChildSiblingTreeNode {
    void *data;
    struct ChildSiblingTreeNode *firstChild;
    struct ChildSiblingTreeNode *nextSibling;
};
