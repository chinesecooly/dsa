//
// Created by Administrator on 2022/3/28.
//

#ifndef INC_2023_PRIORITYQUEUE_H
#define INC_2023_PRIORITYQUEUE_H

#include "../../../util/Util.h"

typedef struct PriorityQueue *PriorityQueue;

/**
 * 构造带头结点的优先队列
 * @param compare
 * @return
 */
PriorityQueue priorityQueueConstructor(int (*compare)(void *, void *)) throws NULL_POINTER_EXCEPTION;

/**
 * 销毁优先队列
 * @param queue
 */
void priorityQueueFinalize(PriorityQueue queue) throws NULL_POINTER_EXCEPTION;

/**
 * 优先队列是否为空
 * @param queue
 * @return
 */
bool priorityQueueIsEmpty(PriorityQueue queue) throws NULL_POINTER_EXCEPTION;

/**
 * 入队
 * @param queue
 * @param element
 */
void priorityQueueEnQueue(PriorityQueue queue, void *element) throws NULL_POINTER_EXCEPTION;

/**
 * 出队
 * @param queue
 * @return
 */
void *priorityQueueDeQueue(PriorityQueue queue) throws NULL_POINTER_EXCEPTION;


#endif //INC_2023_PRIORITYQUEUE_H
