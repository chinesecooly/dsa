//
// Created by Administrator on 2023/4/4.
//
#include "SingleLinkedList.h"

struct SingleLinkedListNode {
    ElementType data;
    struct SingleLinkedListNode *next;
};

/**
 * 构造函数
 * @return 单链表
 */
SingleLinkedList singleLinkedListConstructor() {
    SingleLinkedListNode *head = malloc(sizeof(SingleLinkedListNode));
    head->next = NULL;
    return head;
}

/**
 * 头插法
 * @param elementList
 * @param length
 * @return
 */
SingleLinkedList singleLinkedListHeadConstructor(ElementType *elementList, int length) {
    SingleLinkedList list = singleLinkedListConstructor();
    for (int i = 0; i < length; ++i) {
        SingleLinkedListNode *node = malloc(sizeof(SingleLinkedListNode));
        node->data = *(elementList + i);
        node->next = list->next;
        list->next = node;
    }
    return list;
}

/**
 * 尾插法
 * @param elementList
 * @param length
 * @return
 */
SingleLinkedList singleLinkedListTailConstructor(ElementType *elementList, int length) {
    SingleLinkedList list = singleLinkedListConstructor();
    SingleLinkedListNode *tailNode = list;
    for (int i = 0; i < length; ++i) {
        SingleLinkedListNode *node = malloc(sizeof(SingleLinkedListNode));
        node->data = *(elementList + i);
        node->next = NULL;
        tailNode->next = node;
        tailNode = node;
    }
    return list;
}

/**
 * 按位插入
 * @param singleLinkedList 单链表
 * @param index 位置
 * @param element 元素
 */
void singleLinkedListInsert(SingleLinkedList singleLinkedList, int index,
                            ElementType element) throws INDEX_OUT_OF_RANGE_ERROR {
    if (index < 1) {
        throw Error(INDEX_OUT_OF_RANGE_ERROR, "索引不合法");
    }
    int i = 0;
    SingleLinkedListNode *precursorNode = NULL;
    for (SingleLinkedListNode *node = singleLinkedList; node != NULL && i < index; node = node->next) {
        if (++i == index) {
            precursorNode = node;
            break;
        }
    }
    if (precursorNode == NULL) {
        throw Error(INDEX_OUT_OF_RANGE_ERROR, "索引不合法");
    }
    SingleLinkedListNode *node = malloc(sizeof(SingleLinkedListNode));
    node->data = element;
    node->next = precursorNode->next;
    precursorNode->next = node;
}

/**
 * 按位删除
 * @param singleLinkedList 单链表
 * @param index 位置
 */
void singleLinkedListDelete(SingleLinkedList singleLinkedList, int index) throws INDEX_OUT_OF_RANGE_ERROR {
    if (index < 1) {
        throw Error(INDEX_OUT_OF_RANGE_ERROR, "索引不合法");
    }
    int i = 0;
    SingleLinkedListNode *precursorNode = NULL;
    for (SingleLinkedListNode *node = singleLinkedList; node != NULL && i < index; node = node->next) {
        if (++i == index) {
            precursorNode = node;
            break;
        }
    }
    if (precursorNode == NULL || precursorNode->next == NULL) {
        throw Error(INDEX_OUT_OF_RANGE_ERROR, "索引不合法");
    }
    SingleLinkedListNode *temp = precursorNode->next;
    precursorNode->next = temp->next;
    free(temp);
}

/**
 * 获取索引
 * @param list 单链表
 * @param element 元素
 * @return 位置
 */
int singleLinkedListIndexOf(SingleLinkedList list, ElementType element) {
    int index = 1;
    SingleLinkedListNode *node = list->next;
    for (; node != NULL && node->data != element;) {
        node = node->next;
        index++;
    }
    if (node == NULL) {
        return -1;
    } else {
        return index;
    }
}

/**
 * 获取元素
 * @param list 单链表
 * @param index 索引
 * @return 元素
 */
ElementType
singleLinkedListGet(SingleLinkedList list, int index) throws INDEX_OUT_OF_RANGE_ERROR HAS_NO_ELEMENT_ERROR {
    if (index < 1) {
        throw Error(INDEX_OUT_OF_RANGE_ERROR, "索引不合法");
    }
    int i = 1;
    SingleLinkedListNode *node = list->next;
    for (; node != NULL && i != index;) {
        node = node->next;
        i++;
    }
    if (node == NULL) {
        throw Error(HAS_NO_ELEMENT_ERROR, "单链表不含该元素");
    }
    return node->data;
}

