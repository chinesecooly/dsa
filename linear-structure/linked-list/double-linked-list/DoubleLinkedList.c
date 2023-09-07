//
// Created by Administrator on 2023/4/4.
//
#include "DoubleLinkedList.h"

struct DoubleLinkedListNode {
    void * data;
    struct DoubleLinkedListNode *prior;
    struct DoubleLinkedListNode *next;
};

/**
 * 构造函数
 * @return 双链表
 */
DoubleLinkedList doubleLinkedListConstructor() {
    DoubleLinkedList list = malloc(sizeof(DoubleLinkedListNode));
    list->prior = NULL;
    list->next = NULL;
    return list;
}

