//
// Created by Administrator on 2022/3/24.
//

#ifndef INC_2023_BITREE_H
#define INC_2023_BITREE_H

#include "../constrained-linear-list/LinkQueue.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef int BiTreeElemType;
typedef struct BiTNode BiTNode, *BiTree;

BiTree preInOrderConstruct(BiTreeElemType preOrderList[], BiTreeElemType inOrderList[], int ps, int pe, int bs, int be);

BiTree completeLevelOrderConstruct(BiTreeElemType completeLevelOrderList[], int len, BiTreeElemType filler);

void biTreeFinalize(BiTree this);

void preOrder(BiTree this);

void inOrder(BiTree this);

void postOrder(BiTree this);

void levelOrder(BiTree this);

#endif //INC_2023_BITREE_H