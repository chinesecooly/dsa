//
// Created by Administrator on 2023/4/9.
//
#include "SequenceStack.h"

struct SequenceStack {
    ElementType *data;
    int top;
};

/**
 * 构造站
 * @return
 */
SequenceStack sequenceStackConstructor() {
    SequenceStack stack = malloc(sizeof(struct SequenceStack));
    stack->data = calloc(MAX_SIZE, sizeof(ElementType));
    stack->top = 0;
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
void sequenceStackPush(SequenceStack stack, ElementType element) throws FULL_ERROR {
    if (stack->top == MAX_SIZE) {
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
ElementType sequenceStackPop(SequenceStack stack) throws EMPTY_ERROR{
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
ElementType sequenceStackPeek(SequenceStack stack) throws EMPTY_ERROR{
    if (stack->top == 0) {
        throw Error(EMPTY_ERROR, "栈为空");
    }
    return *(stack->data + stack->top - 1);
}