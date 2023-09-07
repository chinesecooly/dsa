//
// Created by Administrator on 2023/4/9.
//

#include "SequenceQueue.h"

struct SequenceQueue {
    void **data;
    int front;
    int rear;
    int size;
};

/**
 * 构造函数
 * @return
 */
SequenceQueue sequenceQueueConstructor(int size) {
    SequenceQueue queue = malloc(sizeof(struct SequenceQueue));
    queue->data = calloc(size, sizeof(void *));
    queue->front = 0;
    queue->rear = 0;
    queue->size = size;
    return queue;
}

void sequenceQueueDestroy(SequenceQueue queue) {

}

void sequenceQueueEnQueue(SequenceQueue queue, void * element) {

}

void * sequenceQueueDeQueue(SequenceQueue queue) {

}