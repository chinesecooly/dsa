//
// Created by Administrator on 2022/3/18.
//

typedef int ElementType;

struct DLinkList{
    ElementType data;
    struct DLinkList * next;
    struct DLinkList * prior;
};