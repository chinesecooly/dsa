//
// Created by Administrator on 2022/4/11.
//

#include "BSTree.h"

struct BSTNode {
    BSTreeElemType data;
    struct BSTNode *lChild;
    struct BSTNode *rChild;
};

BSTree BSTreeConstruct(BSTreeElemType elems[], int len) {
    BSTree tree = malloc(sizeof(BSTNode));
    for (int i = 0; i < len; ++i) {
        BSTInsert(tree, elems[i]);
    }
}

BSTNode *getParent(BSTree tree, BSTNode *node) {

}

bool isLeft(BSTNode *parent, BSTNode *node) {

}

bool changeNode(BSTNode * parent,BSTNode * node,bool isLeft){

}


BSTNode * getImmediateSuccessor(BSTree rTree){

}

void BSTInsert(BSTree tree, BSTreeElemType elem) {
    if (tree->data == elem) {
        return;
    } else if (tree->data > elem) {
        if (tree->lChild == NULL) {
            tree->lChild = malloc(sizeof(BSTNode));
            tree->lChild->data = elem;
            tree->lChild->lChild = NULL;
            tree->lChild->rChild = NULL;
        } else {
            BSTInsert(tree->lChild, elem);
        }
    } else {
        if (tree->rChild == NULL) {
            tree->rChild = malloc(sizeof(BSTNode));
            tree->rChild->data = elem;
            tree->rChild->lChild = NULL;
            tree->rChild->rChild = NULL;
        } else {
            BSTInsert(tree->rChild, elem);
        }
    }
}

BSTNode *BSTSearch(BSTree tree, BSTreeElemType elem) {
    if (tree != NULL) {
        if (tree->data == elem) {
            return tree;
        } else if (tree->data < elem) {
            return BSTSearch(tree->lChild, elem);
        } else {
            return BSTSearch(tree->rChild, elem);
        }
    } else {
        return NULL;
    }
}

BSTree BSTDelete(BSTree tree, BSTNode *node, BSTNode *parent, bool left) {
    if (node->lChild == NULL && node->rChild == NULL) {
        if(changeNode(parent,NULL,left)){
            return tree;
        } else{
            return NULL;
        }
    } else if (node->lChild != NULL && node->rChild == NULL) {
        if(changeNode(parent,node->lChild,left)){
            return tree;
        } else{
            return node->lChild;
        }
    } else if (node->rChild != NULL && node->lChild == NULL) {
        if(changeNode(parent,node->rChild,left)){
            return tree;
        } else{
            return node->rChild;
        }
    } else {
        BSTNode * ISNode=getImmediateSuccessor(node->rChild);
        node->data=ISNode->data;
        return BSTDelete(tree,ISNode, getParent(node->rChild,ISNode),isLeft(getParent(node->rChild,ISNode),ISNode));
    }
}

void BSTFinalizer(BSTree tree) {
    if (tree != NULL) {
        BSTFinalizer(tree->lChild);
        BSTFinalizer(tree->rChild);
        free(tree);
    }
}