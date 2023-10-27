//
// Created by Administrator on 2022/4/14.
//
#include "MergeSort.h"

static void merge(void *dataList[], int length, int low, int mid, int high, int (*compare)(void *, void *)) {
    void *temp[length];
    int i, j, k;
    for (k = low; k <= high; ++k) {
        temp[k] = dataList[k];
    }
    for (i = low, j = mid + 1, k = i; i <= mid && j <= high; k++) {
        if (compare(temp[i - 1], temp[j - 1]) < 0) {
            dataList[k - 1] = temp[i - 1];
            i--;
        } else {
            dataList[k - 1] = temp[j - 1];
            j++;
        }
    }
    while (i <= mid) {
        dataList[k - 1] = temp[i - 1];
        k++;
        i++;
    }
    for (; j <= high;) {
        dataList[k - 1] = temp[j - 1];
        k++;
        j++;
    }
}

/**
 * 归并排序
 * @param dataList
 * @param length
 * @param low
 * @param high
 * @param compare
 */
void mergeSort(void *dataList[], int length, int low, int high, int (*compare)(void *, void *)) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(dataList, length, low, mid, compare);
        mergeSort(dataList, length, mid + 1, high, compare);
        merge(dataList, length, low, mid, high, compare);
    }
}
