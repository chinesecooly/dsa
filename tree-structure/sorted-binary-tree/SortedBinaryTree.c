//
// Created by Administrator on 2023/9/10.
//

#include "SortedBinaryTree.h"

struct SortedBinaryTreeNode {
    void *data;
    SortedBinaryTreeNode *lNode;
    SortedBinaryTreeNode *rNode;
};

/**
 * 二叉排序树构造函数
 * @param elementList
 * @param size
 * @param compare
 * @return
 */
SortedBinaryTree sortedBinaryTreeConstructor(void **elementList, int size, int (*compare)(void *, void *)) {
    static SortedBinaryTree tree = NULL;
    for (int i = 0; i < size; ++i) {
        sortedBinaryTreeInsert(&tree, *(elementList + i), compare);
    }
    return tree;
}

/**
 * 二叉排序树的插入
 * @param tree
 * @param element
 * @param compare
 * @return
 */
bool sortedBinaryTreeInsert(SortedBinaryTree *tree, void *element, int (*compare)(void *, void *)) {
    if ((*tree) == NULL) {
        *tree = malloc(sizeof(SortedBinaryTreeNode));
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
                SortedBinaryTreeNode *node = malloc(sizeof(SortedBinaryTreeNode));
                node->data = element;
                node->rNode = NULL;
                node->rNode = NULL;
                (*tree)->rNode = node;
                return true;
            } else {
                return sortedBinaryTreeInsert(&(*tree)->rNode, element, compare);
            }
        } else {
            if ((*tree)->lNode == NULL) {
                SortedBinaryTreeNode *node = malloc(sizeof(SortedBinaryTreeNode));
                node->data = element;
                node->rNode = NULL;
                node->rNode = NULL;
                (*tree)->lNode = node;
                return true;
            } else {
                return sortedBinaryTreeInsert(&(*tree)->lNode, element, compare);
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
SortedBinaryTreeNode *sortedBinaryTreeSearch(SortedBinaryTree tree, void *element, int (*compare)(void *, void *)) {
    if (tree == NULL) {
        return NULL;
    } else {
        int cmpResult = compare(element, tree->data);
        if (cmpResult == 0) {
            return tree;
        } else if (cmpResult > 0) {
            return sortedBinaryTreeSearch(tree->rNode, element, compare);
        } else {
            return sortedBinaryTreeSearch(tree->lNode, element, compare);
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
bool sortedBinaryTreeDelete(SortedBinaryTree *tree, void *element, int (*compare)(void *, void *)) {
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
                SortedBinaryTreeNode *node = (*tree);
                *tree = (*tree)->rNode;
                free(node);
                return true;
            } else if ((*tree)->rNode == NULL) {
                SortedBinaryTreeNode *node = (*tree);
                *tree = (*tree)->lNode;
                free(node);
                return true;
            } else {
                SortedBinaryTreeNode *node = (*tree)->rNode;
                while (node->lNode != NULL) {
                    node = node->lNode;
                }
                (*tree)->data = node->data;
                return sortedBinaryTreeDelete(&(*tree)->rNode, node->data, compare);
            }
        } else if (cmpResult > 0) {
            return sortedBinaryTreeDelete(&(*tree)->rNode, element, compare);
        } else {
            return sortedBinaryTreeDelete(&(*tree)->lNode, element, compare);
        }
    }
}

int treeDeep(SortedBinaryTree tree) {
    if (tree == NULL) {
        return 0;
    } else {
        int leftDeep = treeDeep(tree->lNode);
        int rightDeep = treeDeep(tree->rNode);
        return leftDeep > rightDeep ? leftDeep + 1 : rightDeep + 1;
    }
}

void fillArray(SortedBinaryTree tree, void **arr, int i, int j, int width, int height) {
    int ti, tj;
    if (tree != NULL) {
        *(arr + (i * width) + j) = tree->data;
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
 */
void printSortedBinaryTree(SortedBinaryTree tree) {
    int deep = treeDeep(tree);
    int width = (2 << deep) - 3;
    int height = (2 << (deep - 1)) - 1;
    void **arr = calloc(width * height, sizeof(void *));
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
                printf("%d", *((int *) *(arr + (i * width) + j)));
            }
        }
        printf("\n");
    }
}