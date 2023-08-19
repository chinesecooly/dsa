//
// Created by Administrator on 2023/4/9.
//

#ifndef DSA_SEQUENCESTACK_H
#define DSA_SEQUENCESTACK_H

#include "../../../util/Util.h"

typedef struct SequenceStack *SequenceStack;

/**
 * 构造站
 * @return
 */
SequenceStack sequenceStackConstructor();

/**
 * 销毁栈
 * @param stack
 */
void sequenceStackDestroy(SequenceStack stack);

/**
 * 入栈
 * @param stack
 * @param element
 */
void sequenceStackPush(SequenceStack stack, ElementType element) throws FULL_ERROR;

/**
 * 出栈
 * @param stack
 * @return
 */
ElementType sequenceStackPop(SequenceStack stack) throws EMPTY_ERROR;

/**
 * 查看栈顶元素
 * @param stack
 * @return
 */
ElementType sequenceStackPeek(SequenceStack stack) throws EMPTY_ERROR;

#endif //DSA_SEQUENCESTACK_H
