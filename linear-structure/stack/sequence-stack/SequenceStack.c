//
// Created by Administrator on 2023/4/9.
//
#include "SequenceStack.h"

struct SequenceStack {
    void **data;
    int top;
    int size;
};

/**
 * 构造站
 * @return
 */
SequenceStack sequenceStackConstructor(int size) {
    SequenceStack stack = malloc(sizeof(struct SequenceStack));
    stack->data = calloc(size, sizeof(void *));
    stack->top = 0;
    stack->size = size;
    return stack;
}

/**
 * 销毁栈
 * @param stack
 */
void sequenceStackDestroy(SequenceStack stack) {
    free(stack->data);
    free(stack);
}

/**
 * 入栈
 * @param stack
 * @param element
 */
void sequenceStackPush(SequenceStack stack, void *element) throws FULL_ERROR {
    if (stack->top == stack->size) {
        throw Error(FULL_ERROR, "栈已满");
    }
    *(stack->data + stack->top) = element;
    stack->top++;
}

/**
 * 出栈
 * @param stack
 * @return
 */
void *sequenceStackPop(SequenceStack stack) throws EMPTY_ERROR {
    if (stack->top == 0) {
        throw Error(EMPTY_ERROR, "栈为空");
    }
    stack->top--;
    return *(stack->data + stack->top);
}

/**
 * 查看栈顶元素
 * @param stack
 * @return
 */
void *sequenceStackPeek(SequenceStack stack) throws EMPTY_ERROR {
    if (stack->top == 0) {
        throw Error(EMPTY_ERROR, "栈为空");
    }
    return *(stack->data + stack->top - 1);
}

/**
 * 判断栈是否为空
 * @param stack
 * @return
 */
bool sequenceStackIsEmpty(SequenceStack stack) {
    if (stack->top == 0) {
        return true;
    } else {
        return false;
    }
}