//
// Created by Administrator on 2022/3/27.
//

#include "HTree.h"
#include <stdlib.h>
#include <stdio.h>
#include "../linear-structure/queue/priority-queue/PriorityQueue.h"
#include <string.h>

struct HTNode {
    HTreeElemType data;
    WeightType weight;
    struct HTNode *lChild;
    struct HTNode *rChild;
};

int HTNodeCompare(void *a, void *b) {
    HTNode *at = (HTNode *) a;
    HTNode *bt = (HTNode *) b;
    if (at->weight > bt->weight) {
        return -1;
    } else if (at->weight < bt->weight) {
        return 1;
    } else {
        return 0;
    }
}

HTree hTreeConstruct(HTreeElemType data[], WeightType weight[], int len) {
    PriorityQueue queue = PriorityQueueConstruct();
    for (int i = 0; i < len; ++i) {
        HTNode *node = malloc(sizeof(HTNode));
        node->data = data[i];
        node->weight = weight[i];
        node->lChild = NULL;
        node->rChild = NULL;
        PriorityQueueEnQueue(queue, node, HTNodeCompare);
    }
    HTNode *node;
    for (; !PriorityQueueIsEmpty(queue);) {
        node = malloc(sizeof(HTNode *));
        node->lChild = PriorityQueueDeQueue(queue);
        node->rChild = PriorityQueueDeQueue(queue);
        node->weight = node->lChild->weight + node->rChild->weight;
        if (PriorityQueueIsEmpty(queue)) {
            PriorityQueueEnQueue(queue, node, HTNodeCompare);
            break;
        }
        PriorityQueueEnQueue(queue, node, HTNodeCompare);
    }
    HTree tree = PriorityQueueDeQueue(queue);
    PriorityQueueFinalize(queue);
    return tree;
}

char *  huffmanCoding(HTree tree,HTreeElemType elem){
    if(tree!=NULL){
        char * lr=huffmanCoding(tree->lChild,elem);
        char * rr=huffmanCoding(tree->rChild,elem);
        if(lr!=NULL){
            return strcat(realloc(lr, strlen(lr)+1),"0");
        } else if(rr!=NULL){
            return strcat(realloc(rr, strlen(rr)+1),"1");
        } else if(tree->lChild!=NULL&&tree->lChild->lChild==NULL&&tree->lChild->rChild==NULL&&tree->lChild->data==elem){
            return strcat(calloc(sizeof (char ),2),"0");
        } else if(tree->rChild!=NULL&&tree->rChild->lChild==NULL&&tree->rChild->rChild==NULL&&tree->rChild->data==elem){
            return strcat(calloc(sizeof (char ),2),"1");
        } else{
            return NULL;
        }
    } else{
        return NULL;
    }
}

void hTreePreOrder(HTree tree) {
    if (tree != NULL) {
        printf("%d,", tree->data);
        hTreePreOrder(tree->lChild);
        hTreePreOrder(tree->rChild);
    }
}

