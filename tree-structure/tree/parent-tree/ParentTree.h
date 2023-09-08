//
// Created by Administrator on 2023/9/8.
//

#ifndef DSA_PARENTTREE_H
#define DSA_PARENTTREE_H

#include "../../../util/Util.h"

typedef struct ParentTree *ParentTree;


/**
 * 构造函数
 * @param size
 * @param compare
 * @return
 */
ParentTree parentTreeConstructor(int size, int (*compare)(void *, void *));

/**
 * 插入元素
 * @param tree
 * @param parent
 * @param element
 * @return
 */
bool parentTreeInsert(ParentTree tree, void *parent, void *element);

/**
 * 删除操作
 * @param tree
 * @param element
 * @return
 */
bool parentTreeDelete(ParentTree tree, void *element);

/**
 * 查找元素位置
 * @param tree
 * @param element
 * @return
 */
int parentTreeIndexOf(ParentTree tree, void *element);

#endif //DSA_PARENTTREE_H
