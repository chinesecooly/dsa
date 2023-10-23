//
// Created by Administrator on 2022/4/12.
//

#include "InsertSort.h"

void directInsert(InsertSortElemType elems[], int len) {
    for (int i = 1; i < len; ++i) {
        int temp = elems[i];
        for (int j = i - 1; j >= 0; --j) {
            if (temp < elems[j]) {
                elems[j + 1] = elems[j];
                if (j == 0) {
                    elems[j] = temp;
                    break;
                }
            } else {
                elems[j + 1] = temp;
                break;
            }
        }
    }
}

void binaryInsertSort(InsertSortElemType elems[], int len) {
    for (int i = 1; i < len; ++i) {
        int temp = elems[i];
        int mid, high = i - 1, low = 0;
        for (; low <= high;) {
            mid = (high + low) / 2;
            if (elems[mid] > temp) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        for (int j = i; j >= low; j--) {
            elems[j] = elems[j - 1];
        }
        elems[low] = temp;
    }
}

void shellSort(InsertSortElemType elems[], int len) {
    for (int p = len / 2; p >= 1; p /= 2) {
        for (int i = p; i < len; ++i) {
            int temp = elems[i];
            for (int j = i - p; j >= 0; j-=p) {
                if (temp < elems[j]) {
                    elems[j + p] = elems[j];
                    if (j == 0) {
                        elems[j] = temp;
                        break;
                    }
                } else {
                    elems[j + p] = temp;
                    break;
                }
            }
        }
    }
}
