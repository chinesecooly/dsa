//
// Created by Administrator on 2023/8/17.
//
#include "tree-structure/huffman-tree/HuffmanTree.h"
#include "linear-structure/queue/linked-queue/LinkedQueue.h"

int reCompare(void *a, void *b) {
    if (*((int *) a) > *((int *) b)) {
        return -1;
    } else if (*((int *) a) == *((int *) b)) {
        return 0;
    } else {
        return 1;
    }
}

void *weightSum(void *a, void *b) {
    int *sum = malloc(sizeof(int));
    *sum = *((int *) a) + *((int *) b);
    return sum;
}

int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    char *dataList[] = {data, data + 1, data + 2, data + 3, data + 4, data + 5};
    int weight[] = {45, 13, 12, 16, 9, 5};
    int *weightList[] = {weight, weight + 1, weight + 2, weight + 3, weight + 4, weight + 5};
    HuffmanTree tree = huffmanTreeNodeConstructor(dataList, weightList, 6, reCompare, weightSum);
    for (int i = 0; i < 6; ++i) {
        char *code = huffmanCoding(tree, data + i, reCompare);
        printf("%c:%s\n",data[i],code);
    }
    return 0;
}


