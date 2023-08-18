//
// Created by Administrator on 2023/8/18.
//

#include "StaticLinkedList.h"

struct StaticLinkedListNode {
    ElementType data;
    int next;
};

/**
 * 静态链表构造函数
 * @return
 */
StaticLinkedList staticLinkedListConstructor() {
    StaticLinkedList list = calloc(MAX_SIZE, sizeof(struct StaticLinkedListNode));
    return list;
}