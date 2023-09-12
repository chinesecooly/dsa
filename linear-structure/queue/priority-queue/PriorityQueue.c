//
// Created by Administrator on 2022/3/28.
//

#include "PriorityQueue.h"

typedef struct PriorityQueueNode {
    void *data;
    struct PriorityQueueNode *next;
    struct PriorityQueueNode *prior;
} PriorityQueueNode;

struct PriorityQueue {
    PriorityQueueNode *front;
    PriorityQueueNode *rear;

    int (*compare)(void *, void *);
};

/**
 * 构造带头结点的优先队列
 * @param compare
 * @return
 */
PriorityQueue priorityQueueConstructor(int (*compare)(void *, void *)) throws NULL_POINTER_EXCEPTION {
    if (compare == NULL) {
        throw Error(NULL_POINTER_EXCEPTION, "比较函数不能为空");
    }
    PriorityQueue queue = malloc(sizeof(struct PriorityQueue));
    //头结点
    queue->front = queue->rear = malloc(sizeof(PriorityQueueNode));
    queue->front->next = NULL;
    queue->front->prior = NULL;
    queue->compare = compare;
    return queue;
}

/**
 * 销毁优先队列
 * @param queue
 */
void priorityQueueFinalize(PriorityQueue queue) throws NULL_POINTER_EXCEPTION {
    if (queue == NULL) {
        throw Error(NULL_POINTER_EXCEPTION, "优先队列不能为空");
    }
    for (; !priorityQueueIsEmpty(queue);) {
        priorityQueueDeQueue(queue);
    }
    free(queue->front);
    free(queue);
}

/**
 * 优先队列是否为空
 * @param queue
 * @return
 */
bool priorityQueueIsEmpty(PriorityQueue queue) throws NULL_POINTER_EXCEPTION {
    if (queue == NULL) {
        throw Error(NULL_POINTER_EXCEPTION, "优先队列不能为空");
    }
    if (queue->front == queue->rear) {
        return true;
    } else {
        return false;
    }
}

/**
 * 入队
 * @param queue
 * @param element
 */
void priorityQueueEnQueue(PriorityQueue queue, void *element) throws NULL_POINTER_EXCEPTION {
    if (queue == NULL) {
        throw Error(NULL_POINTER_EXCEPTION, "优先队列不能为空");
    }
    PriorityQueueNode *node = malloc(sizeof(PriorityQueueNode));
    node->data = element;
    //如果新加入元素优先级比队尾元素优先级小则直接插入队尾，否则就遍历优先队列找到合适的插入位置
    if (priorityQueueIsEmpty(queue) || queue->compare(queue->rear->data, node->data) > 0) {
        node->next = NULL;
        node->prior = queue->rear;
        queue->rear->next = node;
        queue->rear = node;
    } else {
        for (PriorityQueueNode *temp = queue->front->next; temp != NULL; temp = temp->next) {
            if (queue->compare(temp->data, node->data) <= 0) {
                node->next = temp;
                node->prior = temp->prior;
                temp->prior->next = node;
                temp->prior = node;
                break;
            }
        }
    }
}

/**
 * 出队
 * @param queue
 * @return
 */
void *priorityQueueDeQueue(PriorityQueue queue) throws NULL_POINTER_EXCEPTION {
    if (queue == NULL) {
        throw Error(NULL_POINTER_EXCEPTION, "优先队列不能为空");
    }
    if (!priorityQueueIsEmpty(queue)) {
        PriorityQueueNode *node = queue->front->next;
        void *data = node->data;
        if (queue->rear == node) {
            queue->rear = queue->front;
            queue->front->next = NULL;
        } else {
            queue->front->next = node->next;
            node->next->prior = queue->front;
        }
        free(node);
        return data;
    } else {
        return NULL;
    }
}


