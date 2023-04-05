//
// Created by Administrator on 2023/4/4.
//
#include "DoubleLinkedList.h"

struct Node {
    ElementType data;
    struct Node *last;
    struct Node *next;
};

