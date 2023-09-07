//
// Created by Administrator on 2023/4/4.
//

#ifndef DSA_SEQUENCELIST_H
#define DSA_SEQUENCELIST_H

#include "../../util/Util.h"

//顺序表
typedef struct SequenceList *SequenceList;

/**
 * 构造函数
 * @param size
 * @param compare
 * @return
 */
SequenceList sequenceListConstructor(int size, int (*compare)(void *, void *));

/**
 * 销毁
 * @param sequenceList
 */
void sequenceListDestroy(SequenceList sequenceList);

/**
 * 插入
 * @param sequenceList
 * @param index
 * @param element
 */
void sequenceListInsert(SequenceList sequenceList, int index, void *element) throws INDEX_OUT_OF_RANGE_ERROR;

/**
 * 删除
 * @param sequenceList
 * @param index
 */
void sequenceListDelete(SequenceList sequenceList, int index);

/**
 * 查找下标
 * @param sequenceList
 * @param element
 * @return
 */
int sequenceListIndexOf(SequenceList sequenceList, void *element);

/**
 * 获取元素
 * @param sequenceList
 * @param index
 * @return
 */
void *sequenceListGet(SequenceList sequenceList, int index);

#endif //DSA_SEQUENCELIST_H
