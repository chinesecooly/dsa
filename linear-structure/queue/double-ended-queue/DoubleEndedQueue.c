//
// Created by Administrator on 2023/10/7.
//

#include "DoubleEndedQueue.h"

struct DoubleEndedQueue {
    void **data;
    int front;
    int rear;
    int size;
};
