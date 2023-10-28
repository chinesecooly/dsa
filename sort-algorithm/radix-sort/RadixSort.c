//
// Created by Administrator on 2023/10/27.
//

#include "RadixSort.h"

/**
 * 基数排序
 * @param dataList
 * @param length
 * @param maxLength
 */
void radixSort(int dataList[], int length, int maxLength) {
    LinkedQueue queue = linkedQueueConstructor();
    for (int i = 0; i < length; ++i) {
        linkedQueueEnQueue(queue, dataList + i);
    }
    LinkedQueue queue0 = linkedQueueConstructor();
    LinkedQueue queue1 = linkedQueueConstructor();
    LinkedQueue queue2 = linkedQueueConstructor();
    LinkedQueue queue3 = linkedQueueConstructor();
    LinkedQueue queue4 = linkedQueueConstructor();
    LinkedQueue queue5 = linkedQueueConstructor();
    LinkedQueue queue6 = linkedQueueConstructor();
    LinkedQueue queue7 = linkedQueueConstructor();
    LinkedQueue queue8 = linkedQueueConstructor();
    LinkedQueue queue9 = linkedQueueConstructor();
    LinkedQueue queueList[] = {queue0, queue1, queue2, queue3, queue4, queue5, queue6, queue7, queue8, queue9};
    for (int i = 1; i <= maxLength; ++i) {
        while (!linkedQueueIsEmpty(queue)) {
            void *data = linkedQueueDeQueue(queue);
            int key = *(int *) data / (int) pow(10, i - 1) % 10;
            linkedQueueEnQueue(queueList[key], data);
        }
        for (int j = 0; j < 10; ++j) {
            LinkedQueue keyQueue = queueList[j];
            while (!linkedQueueIsEmpty(keyQueue)) {
                linkedQueueEnQueue(queue, linkedQueueDeQueue(keyQueue));
            }
        }
    }
    while (!linkedQueueIsEmpty(queue)) {
        void *data = linkedQueueDeQueue(queue);
        printf("%d,", *(int *) data);
    }
}
