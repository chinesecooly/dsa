#include "tree-structure/red-black-tree/RedBlackTree.h"
#include "tree-structure/balanced-binary-tree/BalancedBinaryTree.h"

void dataPrint(void *);

int main(int argc, char **argv) {
    int dataList[] = {20, 10, 5, 30, 40, 57, 3, 2, 4, 35, 25, 18, 22, 23, 24, 19, 18};
    RedBlackTree tree = redBlackTreeConstructor(NULL, 0, intCompare);
    for (int i = 0; i < 17; ++i) {
        redBlackTreeInsert(&tree, dataList + i, intCompare);
        redBlackTreePrint(tree, dataPrint);
        printf("-------------\n");
    }
    return 0;
}

//BalancedBinaryTree
//int main(int argc, char **argv) {
//    int dataList[] = {15, 3, 7, 10, 9, 8};
//    BalancedBinaryTree tree = balancedBinaryTreeConstructor(NULL, 0, intCompare);
//    for (int i = 0; i < 6; ++i) {
//        balancedBinaryTreeInsert(&tree, dataList + i, intCompare);
//        balancedBinaryTreePrint(tree, dataPrint);
//        printf("-------------\n");
//    }
//    balancedBinaryTreeDelete(&tree, dataList + 4, intCompare);
//    balancedBinaryTreePrint(tree, dataPrint);
//    printf("-------------\n");
//    return 0;
//}

void dataPrint(void *data) {
    printf("%d", *((int *) data));
}


