//
// Created by Administrator on 2022/3/28.
//

#include "PriorityQueue.h"

struct PriorityNode {
    PriorityQueueElemType data;
    PriorityNode *next;
    PriorityNode * prior;
};

struct PriorityQueue{
    PriorityNode *front;
    PriorityNode *rear;
};

PriorityQueue PriorityQueueConstruct() {
    PriorityQueue queue= malloc(sizeof (struct PriorityQueue));
    queue->front = queue->rear = malloc(sizeof(PriorityNode));
    queue->front->next = NULL;
    queue->front->prior=NULL;
    return queue;
}

void PriorityQueueFinalize(PriorityQueue  queue){
    for(;!PriorityQueueIsEmpty(queue);){
        PriorityQueueDeQueue(queue);
    }
    free(queue);
}

bool PriorityQueueIsEmpty(PriorityQueue queue) {
    if (queue->front == queue->rear) {
        return true;
    } else {
        return false;
    }
}

void PriorityQueueEnQueue(PriorityQueue queue, PriorityQueueElemType x,int (*compare)(void * a,void * b)) {
    PriorityNode *node = malloc(sizeof(PriorityNode));
    node->data = x;
    if(PriorityQueueIsEmpty(queue)||compare(queue->rear->data,node->data)>0){
        node->next=NULL;
        node->prior=queue->rear;
        queue->rear->next = node;
        queue->rear = node;
    }else{
        for (PriorityNode * i=queue->front->next;i!=NULL;i=i->next){
            if(compare(i->data,node->data)<=0){
                node->next=i;
                node->prior=i->prior;
                i->prior->next=node;
                i->prior=node;
                break;
            }
        }
    }
}

PriorityQueueElemType PriorityQueueDeQueue(PriorityQueue  queue) {
    if(!PriorityQueueIsEmpty(queue)){
        PriorityNode *tempNode=queue->front->next;
        PriorityQueueElemType tempData=tempNode->data;
        if(queue->rear==tempNode){
            queue->rear=queue->front;
        }else{
            queue->front->next=tempNode->next;
            tempNode->next->prior=queue->front;
        }
        free(tempNode);
        return tempData;
    }
}


