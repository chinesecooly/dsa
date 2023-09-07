//
// Created by Administrator on 2022/3/19.
//

#include "LinkedQueue.h"

typedef struct LinkedQueueNode {
    void *data;
    struct LinkedQueueNode *next;
} *LinkedQueueNode;

struct LinkedQueue {
    LinkedQueueNode front;
    LinkedQueueNode rear;
};

/**
 * 构造函数
 * @return
 */
LinkedQueue linkedQueueConstructor() {
    LinkedQueue queue = malloc(sizeof(struct LinkedQueue));
    queue->front = queue->rear = malloc(sizeof(struct LinkedQueueNode));
    queue->front->next = NULL;
    return queue;
}

/**
 * 是否为空队列
 * @param queue
 * @return
 */
bool linkedQueueIsEmpty(LinkedQueue queue) {
    if (queue->front == queue->rear) {
        return true;
    } else {
        return false;
    }
}

/**
 * 入栈
 * @param queue
 * @param element
 */
void linkedQueueEnQueue(LinkedQueue queue, void *element) {
    LinkedQueueNode node = malloc(sizeof(struct LinkedQueueNode));
    node->data = element;
    node->next = NULL;
    queue->rear->next = node;
    queue->rear = node;
}

/**
 * 出栈
 * @param queue
 * @return
 */
void *linkedQueueDeQueue(LinkedQueue queue) {
    if (queue->front != queue->rear) {
        LinkedQueueNode tempNode = queue->front->next;
        void *tempData = tempNode->data;
        queue->front->next = tempNode->next;
        if (queue->rear == tempNode) {
            queue->rear = queue->front;
        }
        free(tempNode);
        return tempData;
    } else {
        return NULL;
    }
}

/**
 * 获取头元素
 * @param queue
 * @return
 */
void *linkedQueueGetHead(LinkedQueue queue) {
    if (linkedQueueIsEmpty(queue)) {
        return NULL;
    } else {
        return queue->front->next->data;
    }
}



