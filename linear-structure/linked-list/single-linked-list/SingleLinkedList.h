//
// Created by Administrator on 2023/4/4.
//

#ifndef DSA_SINGLELINKEDLIST_H
#define DSA_SINGLELINKEDLIST_H

#include "../../../util/Util.h"

typedef struct SingleLinkedListNode SingleLinkedListNode, *SingleLinkedList;

/**
 * 构造函数
 * @return 单链表
 */
SingleLinkedList singleLinkedListConstructor();

/**
 * 头插法
 * @param elementList
 * @param length
 * @return
 */
SingleLinkedList singleLinkedListHeadConstructor(void **elementList, int length);

/**
 * 尾插法
 * @param elementList
 * @param length
 * @return
 */
SingleLinkedList singleLinkedListTailConstructor(void **elementList, int length);

/**
 * 按位插入
 * @param singleLinkedList 单链表
 * @param index 位置
 * @param element 元素
 */
void singleLinkedListInsert(SingleLinkedList singleLinkedList, int index,
                            void *element) throws INDEX_OUT_OF_RANGE_ERROR;

/**
 * 按位删除
 * @param singleLinkedList 单链表
 * @param index 位置
 */
void singleLinkedListDelete(SingleLinkedList singleLinkedList, int index) throws INDEX_OUT_OF_RANGE_ERROR;

/**
 * 获取索引
 * @param list
 * @param element
 * @param compare
 * @return
 */
int singleLinkedListIndexOf(SingleLinkedList list, void *element, int (*compare)(void *, void *));

/**
 * 获取元素
 * @param list 单链表
 * @param index 索引
 * @return 元素
 */
void *
singleLinkedListGet(SingleLinkedList list, int index) throws INDEX_OUT_OF_RANGE_ERROR HAS_NO_ELEMENT_ERROR;

#endif //DSA_SINGLELINKEDLIST_H
