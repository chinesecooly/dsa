//
// Created by Administrator on 2022/4/3.
//

#include "SeqSearch.h"

typedef int ElemType;

int seqSearch(ElemType elems[],int len,ElemType key){
    for (int i = 0; i < len; ++i) {
        if(elems[i]==key){
            return i;
        }
    }
}
