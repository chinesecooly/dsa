#include <stdio.h>
#include "sort-algorithm/MergeSort.h"

int main() {
    int arr[] = {13, 1, 2, 3, 7, 6, 5, 4, 10, 9, 8, 11, 12};
    mergeSort(arr, 0, sizeof(arr) / sizeof(int) - 1);
    for (int i = 0; i < sizeof(arr) / sizeof(int); ++i) {
        printf("%d,", arr[i]);
    }
    return 0;
}
