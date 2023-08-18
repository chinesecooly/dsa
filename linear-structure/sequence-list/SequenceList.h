//
// Created by Administrator on 2023/4/4.
//

#ifndef DSA_SEQUENCELIST_H
#define DSA_SEQUENCELIST_H

#include "../../util/Util.h"

#define OUT_RANGE_ERROR

//顺序表
typedef struct SequenceList *SequenceList;

//初始化表
SequenceList sequenceListConstructor();

//销毁表
void sequenceListDestroy(SequenceList);

//插入元素
void sequenceListInsert(SequenceList, int, ElementType) throws OUT_RANGE_ERROR;

//删除元素
void sequenceListDelete(SequenceList, int);

//查找下标
int sequenceListIndexOf(SequenceList, ElementType);

//按位查找
ElementType sequenceListGet(SequenceList, int);

#endif //DSA_SEQUENCELIST_H
