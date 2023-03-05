//
// Created by Administrator on 2022/3/25.
//

#include "ThreadTree.h"

struct ThreadNode{
    ThreadTreeElemType data;
    struct ThreadNode *lChild;
    struct ThreadNode *rChild;
    bool lTag;
    bool rTag;
};

static ThreadTreeElemType visit(ThreadTree tree) {
    return -1;
}

void preOrderThread(ThreadTree tree,ThreadTree pre){
    if(tree!=NULL){
        if(tree->lChild==NULL){
            tree->lChild=pre;
            tree->lTag=true;
        }
        if(pre!=NULL&&pre->rChild==NULL){
            pre->rChild=tree;
            pre->rTag=true;
        }
        pre=tree;   preOrderThread(tree->lChild,pre);
        preOrderThread(tree->rChild,pre);
    }
}

static void preOrder(ThreadTree tree){
    if(tree!=NULL){
        visit(tree);
        if(tree->rTag){
            preOrder(tree->rChild);
        } else{
            preOrder(tree->lChild);
        }
    }
}