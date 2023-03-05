//
// Created by Administrator on 2022/3/20.
//
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *str;
    int length;


} String;

int BF(String src, String target) {
    if (src.length < target.length) {
        return false;
    }
    for (int i = 0; i < src.length; ++i) {
        int temp = i;
        for (int j = 0; j < target.length; ++j, ++temp) {
            if (*(src.str + temp) != *(target.str + j)) {
                break;
            }
            if (j == target.length - 1) {
                return temp - target.length + 1;
            }
        }
    }
    return -1;
}

char charAt(String str, int pos) {
    return *(str.str + pos);
}

int KMP(String src, String target) {
    int next[target.length];
    next[0] = -1;
    for (int ptr = 0, k = -1; ptr < target.length;) {
        if (k == -1 || charAt(target, ptr) == charAt(target, k)) {
            k++;
            ptr++;
            if(charAt(target,ptr)!= charAt(target,k)){
                next[ptr] = k;
            } else{
                next[ptr]=next[k];
            }
        } else {
            k = next[k];
        }
    }

    for (int i = 0, j = 0; i < src.length;) {
        if (charAt(src, i) == charAt(target, j)) {
            i++;
            j++;
        } else {
            j = next[j];
            if (j == -1) {
                i++;
                j++;
            }
        }
        if (j == target.length) {
            return i - target.length;
        }
    }
    return -1;
}






