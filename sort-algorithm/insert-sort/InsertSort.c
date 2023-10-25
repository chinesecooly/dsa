//
// Created by Administrator on 2022/4/12.
//

#include "InsertSort.h"

/**
 * 直接插入排序
 * @param dataList
 * @param length
 */
void directInsert(void *dataList[], int length, int (*compare)(void *, void *)) {
    for (int i = 2; i <= length; ++i) {
        void *data = dataList[i];
        int j;
        for (j = i - 1; j > 0 && compare(data, dataList[j - 1]) < 0; --j) {
            dataList[j + 1 - 1] = dataList[j - 1];
        }
        dataList[j + 1 - 1] = data;
    }
}

/**
 * 折半插入排序
 * @param dataList
 * @param length
 */
void binaryInsertSort(void *dataList[], int length, int (*compare)(void *, void *)) {
    for (int i = 2; i <= length; ++i) {
        void *data = dataList[i];
        int mid, high = i - 1, low = 1;
        while (low <= high) {
            mid = (high + low) / 2;
            if (compare(dataList[mid - 1], data) > 0) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        for (int j = i; j > low; j--) {
            dataList[j - 1] = dataList[j - 1 - 1];
        }
        dataList[low - 1] = data;
    }
}

/**
 * 希尔排序
 * @param dataList
 * @param length
 * @param compare
 */
void shellSort(void *dataList[], int length, int (*compare)(void *, void *)) {
    for (int p = length / 2; p >= 1; p /= 2) {
        for (int i = p + 1; i <= length; ++i) {
            void *data = dataList[i - 1];
            int j;
            for (j = i - p; j > 0 && compare(data, dataList[j - 1]) < 0; j -= p) {
                dataList[j + p - 1] = dataList[j - 1];
            }
            dataList[j + p - 1] = dataList[j - 1];
        }
    }
}
