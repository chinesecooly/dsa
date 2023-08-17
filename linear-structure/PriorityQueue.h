//
// Created by Administrator on 2022/3/28.
//

#ifndef INC_2023_PRIORITYQUEUE_H
#define INC_2023_PRIORITYQUEUE_H

#include <stdbool.h>
#include <stdlib.h>


typedef void *PriorityQueueElemType;

typedef struct PriorityNode PriorityNode;
typedef struct PriorityQueue *PriorityQueue;

PriorityQueue PriorityQueueConstruct();

void PriorityQueueFinalize(PriorityQueue this);

bool PriorityQueueIsEmpty(PriorityQueue this);

void PriorityQueueEnQueue(PriorityQueue queue, PriorityQueueElemType x, int (*compare)(void *a, void *b));

PriorityQueueElemType PriorityQueueDeQueue(PriorityQueue this);


#endif //INC_2023_PRIORITYQUEUE_H
