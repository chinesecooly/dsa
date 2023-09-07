//
// Created by Administrator on 2023/4/4.
//
#include "SequenceList.h"

struct SequenceList {
    void **data;
    int length;
    int size;

    int (*compare)(void *, void *);
};

/**
 * 构造函数
 * @param size
 * @param compare
 * @return
 */
SequenceList sequenceListConstructor(int size, int (*compare)(void *, void *)) {
    SequenceList sequenceList = malloc(sizeof(struct SequenceList));
    sequenceList->data = calloc(size, sizeof(void *));
    sequenceList->length = 0;
    sequenceList->size = size;
    sequenceList->compare = compare;
    return sequenceList;
}

/**
 * 销毁
 * @param sequenceList
 */
void sequenceListDestroy(SequenceList sequenceList) {
    free(sequenceList->data);
    free(sequenceList);
}

/**
 * 插入
 * @param sequenceList
 * @param index
 * @param element
 */
void sequenceListInsert(SequenceList sequenceList, int index, void *element) throws INDEX_OUT_OF_RANGE_ERROR {
    if (sequenceList->length >= sequenceList->size) {
        throw Error(INDEX_OUT_OF_RANGE_ERROR, "顺序表已满");
    }
    if (index < 1 || index > sequenceList->length + 1) {
        throw Error(INDEX_OUT_OF_RANGE_ERROR, "索引不合法");
    }
    for (int i = sequenceList->length; i >= index; i--) {
        *(sequenceList->data + sequenceList->length) = *(sequenceList->data + sequenceList->length - 1);
    }
    *(sequenceList->data + index - 1) = element;
    sequenceList->length++;
}

/**
 * 删除
 * @param sequenceList
 * @param index
 */
void sequenceListDelete(SequenceList sequenceList, int index) {
    if (sequenceList->length == 0) {
        throw Error(INDEX_OUT_OF_RANGE_ERROR, "顺序表为空");
    }
    if (index < 1 || index > sequenceList->length) {
        throw Error(INDEX_OUT_OF_RANGE_ERROR, "索引不合法");
    }
    for (int i = index; i < sequenceList->length; i++) {
        *(sequenceList->data + index - 1) = *(sequenceList->data + index);
    }
}

/**
 * 查找下标
 * @param sequenceList
 * @param element
 * @return
 */
int sequenceListIndexOf(SequenceList sequenceList, void *element) {
    for (int i = 1; i <= sequenceList->length; ++i) {
        if (sequenceList->compare(*(sequenceList->data + i - 1), element) == 0) {
            return i;
        }
    }
    return -1;
}

/**
 * 获取元素
 * @param sequenceList
 * @param index
 * @return
 */
void *sequenceListGet(SequenceList sequenceList, int index) {
    if (index < 1 || index > sequenceList->length) {
        throw Error(INDEX_OUT_OF_RANGE_ERROR, "索引不合法");
    }
    return *(sequenceList->data + index - 1);
}



