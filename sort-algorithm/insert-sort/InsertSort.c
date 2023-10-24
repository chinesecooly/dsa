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

void shellSort(void *dataList[], int len) {
    for (int p = len / 2; p >= 1; p /= 2) {
        for (int i = p; i < len; ++i) {
            int temp = dataList[i];
            for (int j = i - p; j >= 0; j -= p) {
                if (temp < dataList[j]) {
                    dataList[j + p] = dataList[j];
                    if (j == 0) {
                        dataList[j] = temp;
                        break;
                    }
                } else {
                    dataList[j + p] = temp;
                    break;
                }
            }
        }
    }
}
