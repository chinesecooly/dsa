//
// Created by Administrator on 2023/9/8.
//

#ifndef DSA_DISJOINTSET_H
#define DSA_DISJOINTSET_H

#include "../../util/Util.h"

typedef struct DisjointSet *DisjointSet;

/**
 * 构造函数
 * @param size
 * @param compare
 * @return
 */
DisjointSet disjointSetConstructor(int size, int (*compare)(void *, void *));

/**
 * 插入元素
 * @param set
 * @param element
 * @return
 */
bool disjointSetInsert(DisjointSet set, void *element);

/**
 * 查找元素所在集合
 * @param set
 * @param element
 * @return
 */
void *disjointSetFind(DisjointSet set, void *element);

/**
 * 合并集合
 * @param set
 * @param element1
 * @param element2
 * @return
 */
bool disjointSetUnion(DisjointSet set, void *element1, void *element2);

#endif //DSA_DISJOINTSET_H
