//
// Created by Administrator on 2023/4/4.
//

#ifndef DSA_SINGLELINKEDLIST_H
#define DSA_SINGLELINKEDLIST_H

#define LIST_HAS_NO_ELEMENT_ERROR
#define INDEX_OUT_OF_RANGE_ERROR

#include "../../../util/Util.h"

typedef struct SingleLinkedListNode SingleLinkedListNode, *SingleLinkedList;

/**
 * 构造带头节点的单链表
 * @return
 */
SingleLinkedList constructor();

/**
 * 头插法插入元素
 */
void add(SingleLinkedList, ElementType);

/**
 * 获取
 * @return
 */
ElementType get(SingleLinkedList, int)throws LIST_HAS_NO_ELEMENT_ERROR INDEX_OUT_OF_RANGE_ERROR;

/**
 * 链表元素个数
 * @return
 */
int size(SingleLinkedList);

/**
 * 打印
 */
void print(SingleLinkedList);

/**
 * 合并有序链表
 * @return 新链表
 */
SingleLinkedList mergeOrderedLinkedList(SingleLinkedList, SingleLinkedList);

/**
 * 反转链表
 * @return 新链表
 */
SingleLinkedList reverseList(SingleLinkedList);

#endif //DSA_SINGLELINKEDLIST_H
