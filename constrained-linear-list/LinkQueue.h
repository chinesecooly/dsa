//
// Created by Administrator on 2022/3/24.
//

#ifndef INC_2023_LINKQUEUE_H
#define INC_2023_LINKQUEUE_H

#include <stdbool.h>
#include "../error/Error.h"

#define LinkQueueError
typedef void * LinkQueueElemType;

typedef struct LinkNode LinkNode;
typedef struct LinkQueue *LinkQueue;

LinkQueue linkQueueConstruct();
void linkQueueFinalize(LinkQueue  this);

bool isEmpty(LinkQueue this);

void enQueue(LinkQueue this, LinkQueueElemType elem);

LinkQueueElemType deQueue(LinkQueue  this);

LinkQueueElemType getHead(LinkQueue this);

#endif //INC_2023_LINKQUEUE_H
