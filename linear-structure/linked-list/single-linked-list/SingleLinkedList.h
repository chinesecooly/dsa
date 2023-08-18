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
SingleLinkedList singleLinkedListConstructor();

/**
 * 头插法
 * @param elementList
 * @param length
 * @return
 */
SingleLinkedList singleLinkedListHeadConstructor(ElementType *elementList, int length);

/**
 * 尾插法
 * @param elementList
 * @param length
 * @return
 */
SingleLinkedList singleLinkedListTailConstructor(ElementType *elementList, int length);

/**
 * 插入
 */
void singleLinkedListInsert(SingleLinkedList, int, ElementType) throws INDEX_OUT_OF_RANGE_ERROR;

/**
 * 删除
 */
void singleLinkedListDelete(SingleLinkedList, int) throws INDEX_OUT_OF_RANGE_ERROR;

/**
 * 查找索引
 * @param list 单链表
 * @param element 查找元素
 * @return 索引
 */
int singleLinkedListIndexOf(SingleLinkedList list, ElementType element);

/**
 * 按位查找
 * @param list 单链表
 * @param index 索引值
 * @return 元素
 */
ElementType
singleLinkedListGet(SingleLinkedList list, int index) throws INDEX_OUT_OF_RANGE_ERROR LIST_HAS_NO_ELEMENT_ERROR;

#endif //DSA_SINGLELINKEDLIST_H
