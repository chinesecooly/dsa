//
// Created by Administrator on 2022/4/14.
//
#include "MergeSort.h"

static void merge(MergeSortElemType elems[],int low,int mid,int high){
    MergeSortElemType temp[high+1];
    int i,j,k;
    for (k = low; k <=high; ++k) {
        temp[k]=elems[k];
    }
    for (i = low,j=mid+1,k=i; i <=mid&&j<=high; k++) {
        if (temp[i]<temp[j]){
            elems[k]=temp[i++];
        } else{
            elems[k]=temp[j++];
        }
    }
    for (;i<=mid;){
        elems[k++]=temp[i++];
    }
    for (;j<=high;){
        elems[k++]=temp[j++];
    }
}

void mergeSort(MergeSortElemType elems[],int low,int high){
    if (low<high){
        int mid=(low+high)/2;
        mergeSort(elems,low,mid);
        mergeSort(elems,mid+1,high);
        merge(elems,low,mid,high);
    }
}
