//
// Created by Administrator on 2023/9/11.
//

#include "RedBlackTree.h"

#define RED 0
#define BLACK 1

struct RedBlackTreeNode {
    void *data;
    RedBlackTreeNode *lNode;
    RedBlackTreeNode *rNode;
    RedBlackTreeNode *pNode;
    int color;
};

/**
 * 构造函数
 * @param elementList
 * @param size
 * @param compare
 * @return
 */
RedBlackTree redBlackTreeConstructor(void **elementList, int size, int (*compare)(void *, void *)) {
    static RedBlackTree tree = NULL;
    for (int i = 0; i < size; ++i) {
        redBlackTreeInsert(&tree, *(elementList + i), compare);
    }
    return tree;
}

static void reverseColor(RedBlackTreeNode *node) {
    if (node != NULL) {
        if (node->color == RED) {
            node->color = BLACK;
        } else {
            node->color = RED;
        }
    }
}

static void ll(RedBlackTree *tree) {
    RedBlackTreeNode *rootNode = *tree;
    RedBlackTreeNode *rootPNode = (*tree)->pNode;
    RedBlackTreeNode *lNode = rootNode->lNode;
    RedBlackTreeNode *lrNode = lNode->rNode;
    *tree = lNode;
    lNode->pNode = rootPNode;
    lNode->rNode = rootNode;
    rootNode->pNode = lNode;
    rootNode->lNode = lrNode;
    if (lrNode != NULL) {
        lrNode->pNode = rootNode;
    }
    reverseColor(rootNode);
    reverseColor(lNode);
}

static void rr(RedBlackTree *tree) {
    RedBlackTreeNode *rootNode = *tree;
    RedBlackTreeNode *rootPNode = (*tree)->pNode;
    RedBlackTreeNode *rNode = rootNode->rNode;
    RedBlackTreeNode *rlNode = rNode->lNode;
    *tree = rNode;
    rNode->pNode = rootPNode;
    rNode->lNode = rootNode;
    rootNode->pNode = rNode;
    rootNode->rNode = rlNode;
    if (rlNode != NULL) {
        rlNode->pNode = rootNode;
    }
    reverseColor(rootNode);
    reverseColor(rNode);
}

static void lr(RedBlackTree *tree) {
    RedBlackTreeNode *rootNode = *tree;
    RedBlackTreeNode *rootPNode = (*tree)->pNode;
    RedBlackTreeNode *lNode = rootNode->lNode;
    RedBlackTreeNode *lrNode = lNode->rNode;
    RedBlackTreeNode *lrlNode = lrNode->lNode;
    RedBlackTreeNode *lrrNode = lrNode->rNode;
    *tree = lrNode;
    lrNode->pNode = rootPNode;
    lrNode->lNode = lNode;
    lNode->pNode = lrNode;
    lrNode->rNode = rootNode;
    rootNode->pNode = lrNode;
    lNode->rNode = lrlNode;
    if (lrlNode != NULL) {
        lrlNode->pNode = lNode;
    }
    rootNode->lNode = lrrNode;
    if (lrrNode != NULL) {
        lrrNode->pNode = rootNode;
    }
    reverseColor(rootNode);
    reverseColor(lrNode);
}

static void rl(RedBlackTree *tree) {
    RedBlackTreeNode *rootNode = *tree;
    RedBlackTreeNode *rootPNode = (*tree)->pNode;
    RedBlackTreeNode *rNode = rootNode->rNode;
    RedBlackTreeNode *rlNode = rNode->lNode;
    RedBlackTreeNode *rllNode = rlNode->lNode;
    RedBlackTreeNode *rlrNode = rlNode->rNode;
    *tree = rlNode;
    rlNode->pNode = rootPNode;
    rlNode->lNode = rootNode;
    rootNode->pNode = rlNode;
    rlNode->rNode = rNode;
    rNode->pNode = rlNode;
    rNode->lNode = rlrNode;
    if (rlrNode != NULL) {
        rlrNode->pNode = rNode;
    }
    rootNode->rNode = rllNode;
    if (rllNode != NULL) {
        rllNode->pNode = rootNode;
    }
    reverseColor(rootNode);
    reverseColor(rlNode);
}

static void imbalanceAdjust(RedBlackTree tree, RedBlackTree *root) {
    RedBlackTreeNode *fatherNode = tree->pNode;
    if (fatherNode == NULL) {
        return;
    }
    RedBlackTreeNode *grandFatherNode = fatherNode->pNode;
    if (grandFatherNode == NULL) {
        return;
    }
    RedBlackTreeNode *uncleNode = grandFatherNode->lNode == fatherNode ? grandFatherNode->rNode : grandFatherNode->lNode;
    if (!(tree->color == RED && fatherNode->color == RED)) {
        return;
    }
    if (uncleNode == NULL || uncleNode->color == BLACK) {
        if (grandFatherNode->lNode == fatherNode) {
            if (fatherNode->lNode == tree) {
                if (grandFatherNode->pNode == NULL) {
                    ll(root);
                } else {
                    ll(grandFatherNode->pNode->lNode == grandFatherNode ? &(grandFatherNode->pNode->lNode) : &(grandFatherNode->pNode->rNode));
                }
            } else {
                if (grandFatherNode->pNode == NULL) {
                    lr(root);
                } else {
                    lr(grandFatherNode->pNode->lNode == grandFatherNode ? &(grandFatherNode->pNode->lNode) : &(grandFatherNode->pNode->rNode));
                }
            }
        } else {
            if (fatherNode->rNode == tree) {
                if (grandFatherNode->pNode == NULL) {
                    rr(root);
                } else {
                    rr(grandFatherNode->pNode->lNode == grandFatherNode ? &(grandFatherNode->pNode->lNode) : &(grandFatherNode->pNode->rNode));
                }
            } else {
                if (grandFatherNode->pNode == NULL) {
                    rl(root);
                } else {
                    rl(grandFatherNode->pNode->lNode == grandFatherNode ? &(grandFatherNode->pNode->lNode) : &(grandFatherNode->pNode->rNode));
                }
            }
        }
    } else {
        reverseColor(grandFatherNode);
        reverseColor(fatherNode);
        reverseColor(uncleNode);
        if (grandFatherNode->pNode == NULL) {
            grandFatherNode->color = BLACK;
        } else {
            imbalanceAdjust(grandFatherNode, root);
        }
    }
}

static bool insert(RedBlackTree *tree, RedBlackTree *root, void *element, int (*compare)(void *, void *)) {
    if ((*tree) == NULL) {
        *tree = malloc(sizeof(RedBlackTreeNode));
        (*tree)->data = element;
        (*tree)->lNode = NULL;
        (*tree)->rNode = NULL;
        (*tree)->pNode = NULL;
        (*tree)->color = BLACK;
        return true;
    } else {
        int cmpResult = compare(element, (*tree)->data);
        if (cmpResult == 0) {
            return false;
        } else if (cmpResult > 0) {
            if ((*tree)->rNode == NULL) {
                RedBlackTreeNode *node = malloc(sizeof(RedBlackTreeNode));
                node->data = element;
                node->rNode = NULL;
                node->rNode = NULL;
                node->pNode = *tree;
                node->color = RED;
                (*tree)->rNode = node;
                imbalanceAdjust(node, root);
                return true;
            } else {
                return insert(&(*tree)->rNode, root, element, compare);
            }
        } else {
            if ((*tree)->lNode == NULL) {
                RedBlackTreeNode *node = malloc(sizeof(RedBlackTreeNode));
                node->data = element;
                node->rNode = NULL;
                node->rNode = NULL;
                node->pNode = *tree;
                node->color = RED;
                (*tree)->lNode = node;
                imbalanceAdjust(node, root);
                return true;
            } else {
                return insert(&(*tree)->lNode, root, element, compare);
            }
        }
    }
}

/**
 * 二叉排序树的插入
 * @param tree
 * @param element
 * @param compare
 * @return
 */
bool redBlackTreeInsert(RedBlackTree *tree, void *element, int (*compare)(void *, void *)) {
    return insert(tree, tree, element, compare);
}

/**
 * 查找
 * @param tree
 * @param element
 * @param compare
 * @return
 */
RedBlackTreeNode *redBlackTreeSearch(RedBlackTree tree, void *element, int (*compare)(void *, void *)) {
    if (tree == NULL) {
        return NULL;
    } else {
        int cmpResult = compare(element, tree->data);
        if (cmpResult == 0) {
            return tree;
        } else if (cmpResult > 0) {
            return redBlackTreeSearch(tree->rNode, element, compare);
        } else {
            return redBlackTreeSearch(tree->lNode, element, compare);
        }
    }
}

/**
 * 删除元素
 * @param tree
 * @param element
 * @param compare
 * @return
 */
//bool redBlackTreeDelete(RedBlackTree *tree, void *element, int (*compare)(void *, void *)) {
//    if (*tree == NULL) {
//        return false;
//    } else {
//        int cmpResult = compare(element, (*tree)->data);
//        if (cmpResult == 0) {
//            if ((*tree)->lNode == NULL && (*tree)->rNode == NULL) {
//                free(*tree);
//                *tree = NULL;
//                return true;
//            } else if ((*tree)->lNode == NULL) {
//                RedBlackTreeNode *node = (*tree);
//                *tree = (*tree)->rNode;
//                free(node);
//                return true;
//            } else if ((*tree)->rNode == NULL) {
//                RedBlackTreeNode *node = (*tree);
//                *tree = (*tree)->lNode;
//                free(node);
//                return true;
//            } else {
//                RedBlackTreeNode *node = (*tree)->rNode;
//                while (node->lNode != NULL) {
//                    node = node->lNode;
//                }
//                (*tree)->data = node->data;
//                bool result = redBlackTreeDelete(&(*tree)->rNode, node->data, compare);
//                imbalanceAdjust(*tree);
//                return result;
//            }
//        } else if (cmpResult > 0) {
//            bool result = redBlackTreeDelete(&(*tree)->rNode, element, compare);
//            imbalanceAdjust(*tree);
//            return result;
//        } else {
//            bool result = redBlackTreeDelete(&(*tree)->lNode, element, compare);
//            imbalanceAdjust(*tree);
//            return result;
//        }
//    }
//}

/**
 * 二叉树的深度
 * @param tree
 * @return
 */
int redBlackTreeDeep(RedBlackTree tree) {
    if (tree == NULL) {
        return 0;
    } else {
        int leftDeep = redBlackTreeDeep(tree->lNode);
        int rightDeep = redBlackTreeDeep(tree->rNode);
        return leftDeep > rightDeep ? leftDeep + 1 : rightDeep + 1;
    }
}

static void fillArray(RedBlackTree tree, RedBlackTreeNode **arr, int i, int j, int width, int height) {
    int ti, tj;
    if (tree != NULL) {
        *(arr + (i * width) + j) = tree;
        if (tree->lNode != NULL) {
            for (ti = i + 1, tj = j - 1; tj > j - (height - i + 1) / 2; tj--) {
                *(arr + ((ti) * width) + tj) = (void *) (-1);
                ti++;
            }
        }
        if (tree->rNode) {
            for (ti = i + 1, tj = j + 1; tj < j + (height - i + 1) / 2; tj++) {
                *(arr + ((ti) * width) + tj) = (void *) (-2);
                ti++;
            }
        }
        fillArray(tree->lNode, arr, ti, j - (height - i + 1) / 2, width, height);
        fillArray(tree->rNode, arr, ti, j + (height - i + 1) / 2, width, height);
    }
}


/**
 * 打印二叉树
 * @param tree
 * @param dataPrint
 */
void redBlackTreePrint(RedBlackTree tree, void (*dataPrint)(void *)) {
    int deep = redBlackTreeDeep(tree);
    int width = (2 << deep) - 3;
    int height = (2 << (deep - 1)) - 1;
    RedBlackTreeNode **arr = calloc(width * height, sizeof(void *));
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            *(arr + (i * width) + j) = (void *) (-3);
        }
    }
    fillArray(tree, arr, 0, (width - 1) / 2, width, height);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (*(arr + (i * width) + j) == (void *) (-1)) {
                printf("/");
            } else if (*(arr + (i * width) + j) == (void *) (-2)) {
                printf("\\");
            } else if (*(arr + (i * width) + j) == (void *) (-3)) {
                printf(" ");
            } else {
                RedBlackTreeNode *node = *(arr + (i * width) + j);
                printf("%c", node->color == RED ? 'r' : 'b');
                dataPrint(node->data);
            }
        }
        printf("\n");
    }
}