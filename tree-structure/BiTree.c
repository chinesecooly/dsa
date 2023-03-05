//
// Created by Administrator on 2022/3/23.
//
#include "BiTree.h"

struct BiTNode {
    BiTreeElemType data;
    struct BiTNode *lChild;
    struct BiTNode *rChild;
};

void visit(BiTree tree) {
    printf("%d",tree->data);
}

void BiTNodeFinalize(BiTNode * node){
    free(node);
}

void preOrder(BiTree tree) {
    if (tree != NULL) {
        visit(tree);
        preOrder(tree->lChild);
        preOrder(tree->rChild);
    }
}

void inOrder(BiTree tree) {
    if (tree != NULL) {
        inOrder(tree->lChild);
        visit(tree);
        inOrder(tree->rChild);
    }
}

void postOrder(BiTree tree) {
    if (tree != NULL) {
        postOrder(tree->lChild);
        postOrder(tree->rChild);
        visit(tree);
    }
}

void levelOrder(BiTree tree){
    LinkQueue queue= linkQueueConstruct();
    enQueue(queue,tree);
    for (; !isEmpty(queue);){
        BiTree  subTree= deQueue(queue);
        visit(subTree);
        if(subTree->lChild!=NULL){
            enQueue(queue,subTree->lChild);
        }
        if(subTree->rChild!=NULL){
            enQueue(queue,subTree->rChild);
        }
    }
    linkQueueFinalize(queue);
}

BiTree preInOrderConstruct(BiTreeElemType preOrderList[],BiTreeElemType inOrderList[],int ps,int pe,int is,int ie){
    BiTNode *root= malloc(sizeof (BiTNode));
    root->data=preOrderList[ps];
    int lLen,rLen;
    for (int i = is; i <= ie; ++i) {
        if(inOrderList[i]==preOrderList[ps]){
            lLen=i-is;
            rLen=ie-i;
            break;
        }
    }
    if(lLen){
        root->lChild= preInOrderConstruct(preOrderList,inOrderList,ps+1,ps+lLen,is,is+lLen-1);
    } else{
        root->lChild=NULL;
    }
    if(rLen){
        root->rChild= preInOrderConstruct(preOrderList,inOrderList,pe-rLen+1,pe,ie-rLen+1,ie);
    } else{
        root->rChild=NULL;
    }
    return root;
}

BiTree  completeLevelOrderConstruct(BiTreeElemType completeLevelOrderList[],int len,BiTreeElemType filler){
    LinkQueue queue= linkQueueConstruct();
    BiTNode * root= malloc(sizeof (BiTNode));
    root->data=completeLevelOrderList[0];
    enQueue(queue,root);
    for (int i = 1; !isEmpty(queue); ++i) {
        BiTNode * node=deQueue(queue);
        if(node!=NULL){
            if((2*1-1)>=len||(2*i+1-1)>=len){
                node->lChild=NULL;
                node->rChild=NULL;
                continue;
            }
            if(completeLevelOrderList[2*i-1]!=filler){
                node->lChild= malloc(sizeof (BiTNode));
                node->lChild->data=completeLevelOrderList[2*i-1];
                enQueue(queue,node->lChild);
            } else{
                node->lChild=NULL;
                enQueue(queue,NULL);
            }
            if(completeLevelOrderList[2*i+1-1]!=filler){
                node->rChild= malloc(sizeof (BiTNode));
                node->rChild->data=completeLevelOrderList[2*i+1-1];
                enQueue(queue,node->rChild);
            } else{
                node->rChild=NULL;
                enQueue(queue,NULL);
            }
        } else{
            continue;
        }
    }
    linkQueueFinalize(queue);
    return root;
}

void biTreeFinalize(BiTree tree){
    if (tree != NULL) {
        biTreeFinalize(tree->lChild);
        biTreeFinalize(tree->rChild);
        BiTNodeFinalize(tree);
    }
}



