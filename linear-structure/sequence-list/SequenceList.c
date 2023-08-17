//
// Created by Administrator on 2023/4/4.
//
#include "SequenceList.h"

struct SequenceList {
    ElementType *data;
    int length;
};

SequenceList sequenceListConstructor() {
    SequenceList sequenceList = malloc(sizeof(struct SequenceList));
    sequenceList->data = calloc(MAX_SIZE, sizeof(ElementType));
    sequenceList->length = 0;
    return sequenceList;
}

void sequenceListDestroy(SequenceList sequenceList) {
    free(sequenceList->data);
    free(sequenceList);
}

void sequenceListInsert(SequenceList sequenceList, int index, ElementType element) throws OUT_RANGE_ERROR {
    if (sequenceList->length >= MAX_SIZE) {
        throw Error(OUT_RANGE_ERROR, "顺序表已满");
    }
    if (index < 1 || index > sequenceList->length + 1) {
        throw Error(OUT_RANGE_ERROR, "索引不合法");
    }
    for (int i = sequenceList->length; i >= index; i--) {
        *(sequenceList->data + sequenceList->length) = *(sequenceList->data + sequenceList->length - 1);
    }
    *(sequenceList->data + index - 1) = element;
    sequenceList->length++;
}

void sequenceListDelete(SequenceList sequenceList, int index) {
    if (sequenceList->length == 0) {
        throw Error(OUT_RANGE_ERROR, "顺序表为空");
    }
    if (index < 1 || index > sequenceList->length) {
        throw Error(OUT_RANGE_ERROR, "索引不合法");
    }
    for (int i = index; i < sequenceList->length; i++) {
        *(sequenceList->data + index - 1) = *(sequenceList->data + index);
    }
}

int sequenceListIndexOf(SequenceList sequenceList, ElementType element) {
    for (int i = 1; i <= sequenceList->length; ++i) {
        if (*(sequenceList->data + i - 1) == element) {
            return i;
        }
    }
    return -1;
}

ElementType sequenceListGet(SequenceList sequenceList, int index) {
    if (index < 1 || index > sequenceList->length) {
        throw Error(OUT_RANGE_ERROR, "索引不合法");
    }
    return *(sequenceList->data + index - 1);
}



