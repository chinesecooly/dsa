//
// Created by Administrator on 2023/9/11.
//

#include "BalancedBinaryTree.h"

struct BalancedBinaryTreeNode {
    void *data;
    BalancedBinaryTreeNode *lNode;
    BalancedBinaryTreeNode *rNode;
};

/**
 * 二叉排序树构造函数
 * @param elementList
 * @param size
 * @param compare
 * @return
 */
BalancedBinaryTree balancedBinaryTreeConstructor(void **elementList, int size, int (*compare)(void *, void *)) {
    static BalancedBinaryTree tree = NULL;
    for (int i = 0; i < size; ++i) {
        balancedBinaryTreeInsert(&tree, *(elementList + i), compare);
    }
    return tree;
}

void ll(BalancedBinaryTree tree) {
    BalancedBinaryTreeNode *lNode = tree->lNode;
    void *lNodeData = lNode->data;
    BalancedBinaryTreeNode *rNode = tree->rNode;
    lNode->data = tree->data;
    tree->data = lNodeData;
    tree->lNode = lNode->lNode;
    tree->rNode = lNode;
    lNode->lNode = rNode;
}

void rr(BalancedBinaryTree tree) {
    BalancedBinaryTreeNode *lNode = tree->lNode;
    BalancedBinaryTreeNode *rNode = tree->rNode;
    void *rNodeData = rNode->data;
    rNode->data = tree->data;
    tree->data = rNodeData;
    tree->rNode = rNode->rNode;
    tree->lNode = rNode;
    rNode->rNode = rNode->lNode;
    rNode->lNode = lNode;
}

void lr(BalancedBinaryTree tree) {
    BalancedBinaryTreeNode *rNode = tree->rNode;
    BalancedBinaryTreeNode *lrNode = tree->lNode->rNode;
    void *lrNodeData = lrNode->data;
    lrNode->data = tree->data;
    tree->data = lrNodeData;
    tree->lNode->rNode = lrNode->lNode;
    tree->rNode = lrNode;
    lrNode->lNode = lrNode->rNode;
    lrNode->rNode = rNode;
}

void rl(BalancedBinaryTree tree) {
    BalancedBinaryTreeNode *lNode = tree->lNode;
    BalancedBinaryTreeNode *rlNode = tree->rNode->lNode;
    void *rlData = rlNode->data;
    rlNode->data = tree->data;
    tree->data = rlData;
    tree->rNode->lNode = rlNode->rNode;
    tree->lNode = rlNode;
    rlNode->rNode = rlNode->lNode;
    rlNode->lNode = lNode;
}

void imbalanceAdjust(BalancedBinaryTree tree) {
    int lDeep = balancedBinaryTreeDeep(tree->lNode);
    int rDeep = balancedBinaryTreeDeep(tree->rNode);
    int balance = lDeep - rDeep;
    if (balance > 1) {
        lDeep = balancedBinaryTreeDeep(tree->lNode->lNode);
        rDeep = balancedBinaryTreeDeep(tree->lNode->rNode);
        //左左和左右
        if (lDeep > rDeep) {
            ll(tree);
        } else {
            lr(tree);
        }
    } else if (balance < -1) {
        lDeep = balancedBinaryTreeDeep(tree->rNode->lNode);
        rDeep = balancedBinaryTreeDeep(tree->rNode->rNode);
        //右右和右左
        if (rDeep > lDeep) {
            rr(tree);
        } else {
            rl(tree);
        }
    } else {
        return;
    }
}

/**
 * 二叉排序树的插入
 * @param tree
 * @param element
 * @param compare
 * @return
 */
bool balancedBinaryTreeInsert(BalancedBinaryTree *tree, void *element, int (*compare)(void *, void *)) {
    if ((*tree) == NULL) {
        *tree = malloc(sizeof(BalancedBinaryTreeNode));
        (*tree)->data = element;
        (*tree)->lNode = NULL;
        (*tree)->rNode = NULL;
        return true;
    } else {
        int cmpResult = compare(element, (*tree)->data);
        if (cmpResult == 0) {
            return false;
        } else if (cmpResult > 0) {
            if ((*tree)->rNode == NULL) {
                BalancedBinaryTreeNode *node = malloc(sizeof(BalancedBinaryTreeNode));
                node->data = element;
                node->rNode = NULL;
                node->rNode = NULL;
                (*tree)->rNode = node;
                return true;
            } else {
                bool result = balancedBinaryTreeInsert(&(*tree)->rNode, element, compare);
                imbalanceAdjust(*tree);
                return result;
            }
        } else {
            if ((*tree)->lNode == NULL) {
                BalancedBinaryTreeNode *node = malloc(sizeof(BalancedBinaryTreeNode));
                node->data = element;
                node->rNode = NULL;
                node->rNode = NULL;
                (*tree)->lNode = node;
                return true;
            } else {
                bool result = balancedBinaryTreeInsert(&(*tree)->lNode, element, compare);
                imbalanceAdjust(*tree);
                return result;
            }
        }
    }
}

/**
 * 二叉排序树的查找
 * @param tree
 * @param element
 * @param compare
 * @return
 */
BalancedBinaryTreeNode *balancedBinaryTreeSearch(BalancedBinaryTree tree, void *element, int (*compare)(void *, void *)) {
    if (tree == NULL) {
        return NULL;
    } else {
        int cmpResult = compare(element, tree->data);
        if (cmpResult == 0) {
            return tree;
        } else if (cmpResult > 0) {
            return balancedBinaryTreeSearch(tree->rNode, element, compare);
        } else {
            return balancedBinaryTreeSearch(tree->lNode, element, compare);
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
bool balancedBinaryTreeDelete(BalancedBinaryTree *tree, void *element, int (*compare)(void *, void *)) {
    if (*tree == NULL) {
        return false;
    } else {
        int cmpResult = compare(element, (*tree)->data);
        if (cmpResult == 0) {
            if ((*tree)->lNode == NULL && (*tree)->rNode == NULL) {
                free(*tree);
                *tree = NULL;
                return true;
            } else if ((*tree)->lNode == NULL) {
                BalancedBinaryTreeNode *node = (*tree);
                *tree = (*tree)->rNode;
                free(node);
                return true;
            } else if ((*tree)->rNode == NULL) {
                BalancedBinaryTreeNode *node = (*tree);
                *tree = (*tree)->lNode;
                free(node);
                return true;
            } else {
                BalancedBinaryTreeNode *node = (*tree)->rNode;
                while (node->lNode != NULL) {
                    node = node->lNode;
                }
                (*tree)->data = node->data;
                bool result = balancedBinaryTreeDelete(&(*tree)->rNode, node->data, compare);
                imbalanceAdjust(*tree);
                return result;
            }
        } else if (cmpResult > 0) {
            bool result = balancedBinaryTreeDelete(&(*tree)->rNode, element, compare);
            imbalanceAdjust(*tree);
            return result;
        } else {
            bool result = balancedBinaryTreeDelete(&(*tree)->lNode, element, compare);
            imbalanceAdjust(*tree);
            return result;
        }
    }
}

/**
 * 二叉树的深度
 * @param tree
 * @return
 */
int balancedBinaryTreeDeep(BalancedBinaryTree tree) {
    if (tree == NULL) {
        return 0;
    } else {
        int leftDeep = balancedBinaryTreeDeep(tree->lNode);
        int rightDeep = balancedBinaryTreeDeep(tree->rNode);
        return leftDeep > rightDeep ? leftDeep + 1 : rightDeep + 1;
    }
}

static void fillArray(BalancedBinaryTree tree, BalancedBinaryTreeNode **arr, int i, int j, int width, int height) {
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
void balancedBinaryTreePrint(BalancedBinaryTree tree, void (*dataPrint)(void *)) {
    int deep = balancedBinaryTreeDeep(tree);
    int width = (2 << deep) - 3;
    int height = (2 << (deep - 1)) - 1;
    BalancedBinaryTreeNode **arr = calloc(width * height, sizeof(void *));
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
                BalancedBinaryTreeNode *node = *(arr + (i * width) + j);
                dataPrint(node->data);
            }
        }
        printf("\n");
    }
}

