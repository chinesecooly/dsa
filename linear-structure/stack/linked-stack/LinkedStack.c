//
// Created by Administrator on 2023/4/9.
//

#include "LinkedStack.h"

struct LinkedStackNode {
    ElementType data;
    struct LinkedStackNode *next;
};

/**
 * 构造函数
 * @return
 */
LinkedStack linkedStackConstructor() {
    LinkedStack stack = malloc(sizeof(LinkedStackNode));
    stack->next = NULL;
    return stack;
}

