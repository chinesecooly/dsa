//
// Created by Administrator on 2022/3/19.
//

#include "LinkQueue.h"
#include <stdlib.h>

struct LinkNode {
    LinkQueueElemType data;
    LinkNode *next;
};

struct LinkQueue{
    LinkNode *front;
    LinkNode *rear;
};

LinkQueue linkQueueConstruct() {
    LinkQueue queue= malloc(sizeof (struct LinkQueue));
    queue->front = queue->rear = malloc(sizeof(LinkNode));
    queue->front->next = NULL;
    return queue;
}

void linkQueueFinalize(LinkQueue  queue){
    for(;!isEmpty(queue);){
        deQueue(queue);
    }
    free(queue);
}

bool isEmpty(LinkQueue queue) {
    if (queue->front == queue->rear) {
        return true;
    } else {
        return false;
    }
}

void enQueue(LinkQueue queue, LinkQueueElemType x) {
    LinkNode *node = malloc(sizeof(LinkNode));
    node->data = x;
    node->next=NULL;
    queue->rear->next = node;
    queue->rear = node;
}

LinkQueueElemType deQueue(LinkQueue  queue) {
    if(queue->front!=queue->rear){
        LinkNode *tempNode=queue->front->next;
        LinkQueueElemType tempData=tempNode->data;
        queue->front->next=tempNode->next;
        if(queue->rear==tempNode){
            queue->rear=queue->front;
        }
        free(tempNode);
        return tempData;
    } else{
        return NULL;
    }
}

LinkQueueElemType getHead(LinkQueue queue){
    if(isEmpty(queue)){
        return NULL;
    } else{
        return queue->front->next->data;
    }
}



