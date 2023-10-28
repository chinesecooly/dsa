//
// Created by Administrator on 2022/4/13.
//

#include "SwapSort.h"

static void swap(void **a, void **b) {
    void *temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * 冒泡排序
 * @param dataList
 * @param length
 * @param compare
 */
void bubbleSort(void *dataList[], int length, int (*compare)(void *, void *)) {
    for (int i = 1; i <= length - 1; i++) {
        bool flag = false;
        for (int j = length; j > i; j--) {
            if (compare(dataList[j - 1], dataList[j - 1 - 1]) < 0) {
                swap(dataList + j - 1, dataList + j - 1 - 1);
                flag = true;
            }
        }
        if (!flag) {
            break;
        }
    }
}

static int partition(void *dataList[], int low, int high, int (*compare)(void *, void *)) {
    void *pivot = dataList[low - 1];
    while (low < high) {
        while (low < high && compare(dataList[high - 1], pivot) > 0) {
            high--;
        }
        dataList[low - 1] = dataList[high - 1];
        while (low < high && compare(dataList[low - 1], pivot) <= 0) {
            low++;
        }
        dataList[high - 1] = dataList[low - 1];
    }
    dataList[low - 1] = pivot;
    return low;
}

/**
 * 快速排序
 * @param dataList
 * @param low
 * @param high
 * @param compare
 */
void quickSort(void *dataList[], int low, int high, int (*compare)(void *, void *)) {
    if (low < high) {
        int pivotPos = partition(dataList, low, high, compare);
        quickSort(dataList, low, pivotPos - 1, compare);
        quickSort(dataList, pivotPos + 1, high, compare);
    }
}
