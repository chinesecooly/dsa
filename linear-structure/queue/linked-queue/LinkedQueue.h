//
// Created by Administrator on 2022/3/24.
//

#ifndef INC_2023_LINKQUEUE_H
#define INC_2023_LINKQUEUE_H

#include "../../../util/Util.h"

typedef struct LinkedQueue *LinkedQueue;

/**
 * 构造函数
 * @return
 */
LinkedQueue linkedQueueConstructor();

/**
 * 是否为空队列
 * @param queue
 * @return
 */
bool linkedQueueIsEmpty(LinkedQueue queue);

/**
 * 入栈
 * @param queue
 * @param element
 */
void linkedQueueEnQueue(LinkedQueue queue, void *element);

/**
 * 出栈
 * @param queue
 * @return
 */
void *linkedQueueDeQueue(LinkedQueue queue);

/**
 * 获取头元素
 * @param queue
 * @return
 */
void *linkedQueueGetHead(LinkedQueue queue);

#endif //INC_2023_LINKQUEUE_H
