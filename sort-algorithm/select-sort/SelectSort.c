//
// Created by Administrator on 2022/4/14.
//

#include "SelectSort.h"

void SimpleSelectSort(SelectSortElemType elems[], int len) {
    for (int i = 0; i < len - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < len; ++j) {
            if (elems[j] < elems[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = elems[i];
            elems[i] = elems[minIndex];
            elems[minIndex] = temp;
        }
    }
}

static void headAdjust(SelectSortElemType elems[], int rootIndex, int len) {
    int root = elems[rootIndex];
    for (int i = 2 * rootIndex; i < len; i *= 2) {
        if (i + 1 < len && elems[i + 1] > elems[i]) {
            i++;
        }
        if (root >= elems[i]) {
            break;
        } else {
            elems[rootIndex] = elems[i];
            elems[i] = root;
            rootIndex = i;
        }
    }
}

static void buildMaxHead(SelectSortElemType elems[], int len) {
    for (int i = len / 2; i >= 0; i--) {
        headAdjust(elems, i, len);
    }
}

void headSort(SelectSortElemType elems[], int len) {
    buildMaxHead(elems, len);
    for (int i = len; i >0; i--) {
        int temp = elems[0];
        elems[0] = elems[i - 1];
        elems[i - 1] = temp;
        headAdjust(elems, 0, i - 1);
    }
}
