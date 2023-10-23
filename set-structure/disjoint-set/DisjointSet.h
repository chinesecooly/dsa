//
// Created by Administrator on 2023/9/8.
//

#ifndef DSA_DISJOINTSET_H
#define DSA_DISJOINTSET_H

#include "../../util/Util.h"

/**
 * 并查集是一种简单的集合，用于解决图中两个顶点是否含有路径的问题，它包含以下三种操作：
- construct(s)：将集合s中的每个元素初始化为只有一个单元素的子集合。
- union(s,root1,root2)：把集合s中的子集合root2并入到root1，前提是root2和root1互不相交。
- find(s,x)：查找集合s中单元素x所在的子集合，并返回该子集合的根结点。

通常使用树的双亲表示法作为并查集的存储结构。每个子集合以一棵树表示，所有表示子集合的树构成表示全集和的森林，存放在数组中。通常用数组元素的下标代表元素名，用根结点的下标代表子集合名，根结点的双亲结点为负数。
 */

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
