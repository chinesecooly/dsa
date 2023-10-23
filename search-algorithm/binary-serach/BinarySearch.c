//
// Created by Administrator on 2023/9/8.
//

#include "BinarySearch.h"

int binarySearch(const int searchTable[], int length, int key) {
    int low = 1, high = length, mid;
    for (; low <= high;) {
        mid = (low + high) / 2;
        if (searchTable[mid - 1] == key) {
            return mid;
        } else if (searchTable[mid - 1] > key) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}