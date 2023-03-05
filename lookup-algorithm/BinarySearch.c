//
// Created by Administrator on 2022/4/3.
//

#include "BinarySearch.h"

typedef int ElemType;

int binarySearch(ElemType elems[],int len,ElemType key){
    int low=0,height=len-1,mid;
    for (;low<=height;){
        mid=(height-low)/2;
        if(elems[mid]==key){
            return mid;
        } else if(elems[mid]>key){
            height=mid-1;
        } else{
            low=mid+1;
        }
    }
    return -1;
}
