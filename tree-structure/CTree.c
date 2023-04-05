//
// Created by Administrator on 2022/3/26.
//

#include "CTree.h"
#include "../linearList/linkList/SingleLinkedList.h"

struct CTNode{
    CTreeElemType data;
    SingleLinkedList childIndexLinkList;
};

struct CTree{
    CTNode *nodes[MAX_TREE_SIZE];
    int n;
};