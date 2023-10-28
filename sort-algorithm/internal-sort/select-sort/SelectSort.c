//
// Created by Administrator on 2022/4/14.
//

#include "SelectSort.h"

static void swap(void **a, void **b) {
    void *temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * 简单选择排序
 * @param dataList
 * @param length
 * @param compare
 */
void SimpleSelectSort(void *dataList[], int length, int (*compare)(void *, void *)) {
    for (int i = 1; i < length; ++i) {
        int minIndex = i;
        for (int j = i + 1; j <= length; ++j) {
            if (compare(dataList[j], dataList[minIndex]) < 0) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(dataList[i], dataList[minIndex]);
        }
    }
}

static void heapAdjust(void **dataList, int rootIndex, int length, int (*compare)(void *, void *)) {
    void *root = dataList[rootIndex - 1];
    //i指向左孩子
    for (int i = 2 * rootIndex; i <= length; i *= 2) {
        //如果右孩子>左孩子，则让i指向右孩子
        if (i < length && compare(dataList[i + 1 - 1], dataList[i - 1]) > 0) {
            i++;
        }
        if (compare(root, dataList[i - 1]) > 0) {
            break;
        } else {
            dataList[rootIndex - 1] = dataList[i - 1];
            rootIndex = i;
        }
    }
    dataList[rootIndex - 1] = root;
}

static void buildMaxHeap(void **dataList, int length, int (*compare)(void *, void *)) {
    for (int i = length / 2; i > 0; i--) {
        heapAdjust(dataList, i, length, compare);
    }
}

/**
 * 堆排序
 * @param dataList
 * @param length
 * @param compare
 */
void heapSort(void **dataList, int length, int (*compare)(void *, void *)) {
    buildMaxHeap(dataList, length, compare);
    for (int i = length; i > 1; i--) {
        swap(dataList[i - 1], dataList[1 - 1]);
        heapAdjust(dataList, 1 - 1, i - 1, compare);
    }
}
