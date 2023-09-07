//
// Created by Administrator on 2023/8/18.
//

#include "StaticLinkedList.h"

struct StaticLinkedListNode {
    void * data;
    int next;
};

/**
 * 静态链表构造函数
 * @return
 */
StaticLinkedList staticLinkedListConstructor(int size) {
    StaticLinkedList list = calloc(size, sizeof(struct StaticLinkedListNode));
    return list;
}