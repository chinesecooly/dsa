//
// Created by Administrator on 2022/3/26.
//

#include "CTree.h"
#include "../general-linear-list/LinkList.h"

struct CTNode{
    CTreeElemType data;
    LinkList childIndexLinkList;
};

struct CTree{
    CTNode *nodes[MAX_TREE_SIZE];
    int n;
};