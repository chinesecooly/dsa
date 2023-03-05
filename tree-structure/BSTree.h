//
// Created by Administrator on 2022/4/11.
//

#ifndef INC_2023_BSTREE_H
#define INC_2023_BSTREE_H
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int BSTreeElemType;
typedef struct BSTNode BSTNode, *BSTree;

BSTree BSTreeConstruct(BSTreeElemType elems[],int len);
void BSTInsert(BSTree tree, BSTreeElemType elem);
BSTNode *BSTSearch(BSTree tree, BSTreeElemType elem);
void BSTFinalizer(BSTree tree);

#endif //INC_2023_BSTREE_H
