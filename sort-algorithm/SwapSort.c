//
// Created by Administrator on 2022/4/13.
//

#include "SwapSort.h"

void bubbleSort(SwapSortElemType elems[],int len){
    for (int i = 0; i <len; i++) {
        bool flag=false;
        for (int j = len-1; j >i; j--) {
            if (elems[j]<elems[j-1]){
                int temp=elems[j];
                elems[j]=elems[j-1];
                elems[j-1]=temp;
                flag=true;
            }
        }
        if (!flag){
            break;
        }
    }
}

static int partition(SwapSortElemType elems[],int low,int high){
    int pivot=elems[low];
    for (;low<high;){
        for (;low<high&&elems[high]>=pivot;){
            high--;
        }
        elems[low]=elems[high];
        for (;low<high&&elems[low]<=pivot;){
            low++;
        }
        elems[high]=elems[low];
    }
    elems[low]=pivot;
    return low;
}

void quickSort(SwapSortElemType elems[],int low,int high){
    if (low<high){
        int pivotPos=partition(elems,low,high);
        quickSort(elems,low,pivotPos-1);
        quickSort(elems,pivotPos+1,high);
    }
}
