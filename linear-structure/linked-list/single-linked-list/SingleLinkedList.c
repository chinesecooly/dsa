//
// Created by Administrator on 2023/4/4.
//
#include "SingleLinkedList.h"

struct SingleLinkedListNode {
    ElementType data;
    struct SingleLinkedListNode *next;
};

SingleLinkedList singleLinkedListConstructor() {
    Node *head = (Node *) malloc(sizeof(Node));
    head->next = NULL;
    return head;
}

//ElementType get(SingleLinkedList list, int index) throws LIST_HAS_NO_ELEMENT_ERROR INDEX_OUT_OF_RANGE_ERROR {
//    int i = 0;
//    if (list->next == NULL) {
//        throw Error(LIST_HAS_NO_ELEMENT_ERROR, "集合为空");
//    }
//    for (Node *node = list->next; node != NULL; node = node->next) {
//        ++i;
//        if (i == index) {
//            return node->data;
//        }
//    }
//    throw Error(INDEX_OUT_OF_RANGE_ERROR, "索引超出范围");
//}

void add(SingleLinkedList list, ElementType element) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->data = element;
    node->next = list->next;
    list->next = node;
}

int size(SingleLinkedList list) {
    int size = 0;
    for (Node *node = list; node->next != NULL; node = node->next) {
        size++;
    }
    return size;
}

void print(SingleLinkedList list) {
    for (Node *node = list; node->next != NULL; node = node->next) {
        printf("%d\n", node->data);
    }
}

SingleLinkedList mergeOrderedLinkedList(SingleLinkedList l1, SingleLinkedList l2) {
    //返回最小的节点
    if (l1 == NULL) {
        return l2;
    } else if (l2 == NULL) {
        return l1;
    } else if (l1->data < l2->data) {
        l1->next = mergeOrderedLinkedList(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeOrderedLinkedList(l1, l2->next);
        return l2;
    }
}

//SingleLinkedList reverseList(SingleLinkedList list) {
//    if (list->next==NULL){
//       return list;
//    } else{
//        Node * head=reverseList(list->next);
//        for (Node * node=head;;node=node->next){
//            if (node->next==NULL){
//                node->next=list;
//                break;
//            }
//        }
//        list->next=NULL;
//        return head;
//    }
//}

SingleLinkedList reverseList(SingleLinkedList list) {
    if (list->next == NULL) {
        return list;
    } else {
        Node *head = reverseList(list->next);
        list->next->next = list;
        list->next = NULL;
        return head;
    }
}
