//
// Created by Administrator on 2022/4/13.
//

#include "SwapSort.h"

void swap(void **a, void **b) {
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
    int pivot = dataList[low];
    for (; low < high;) {
        for (; low < high && dataList[high] >= pivot;) {
            high--;
        }
        dataList[low] = dataList[high];
        for (; low < high && dataList[low] <= pivot;) {
            low++;
        }
        dataList[high] = dataList[low];
    }
    dataList[low] = pivot;
    return low;
}

void quickSort(void *dataList[], int low, int high, int (*compare)(void *, void *)) {
    if (low < high) {
        int pivotPos = partition(dataList, low, high);
        quickSort(dataList, low, pivotPos - 1);
        quickSort(dataList, pivotPos + 1, high);
    }
}
