//
// Created by Administrator on 2022/3/20.
//
#include "String.h"

struct String {
    char *ch;
    int length;
};

/**
 * 构造函数
 * @param str
 * @return
 */
String stringConstructor(char *str) {
    String string = malloc(sizeof(String));
    string->ch = str;
    string->length = (int) strlen(str);
    return string;
}

/**
 * 查找字符位置
 * @param str
 * @param pos
 * @return
 */
char charAt(String str, int pos) throws INDEX_OUT_OF_RANGE_ERROR {
    if (pos < 1 || pos > str->length) {
        throw Error(INDEX_OUT_OF_RANGE_ERROR, "位置异常");
    }
    return *(str->ch + pos - 1);
}

/**
 * BF算法
 * @param src
 * @param target
 * @return
 */
int BF(String src, String target) {
    int i = 1, j = 1;
    while (i <= src->length && j <= target->length) {
        if (*(src->ch + i - 1) == *(target->ch + j - 1)) {
            i++;
            j++;
        } else {
            i = i - j + 2;
            j = 1;
        }
    }
    if (j > target->length) {
        return i - target->length;
    } else {
        return 0;
    }
}

/**
 * 获取next数组
 * @param src
 * @param target
 * @return
 */
int *getNext(String target) {
    int *next = calloc(target->length + 1, sizeof(int));
    *(next + 1) = 0;
    int i = 1, j = 0;
    while (i < target->length) {
        if (j == 0 || charAt(target, i) == charAt(target, j)) {
            next[++i] = ++j;
        } else {
            j = next[j];
        }
    }
}

/**
 * KMP算法
 * @param src
 * @param target
 * @return
 */
int KMP(String src, String target) {
    int *next = getNext(target);
    int i = 1, j = 1;
    while (i <= src->length && j <= target->length) {
        if (j == 0 || charAt(target, i) == charAt(target, j)) {
            i++;
            j++;
        } else {
            j = *(next + j);
        }
    }
    if (j > target->length) {
        return i - target->length;
    } else {
        return 0;
    }
}

/**
 * 获取nextVal数组
 * @param src
 * @param target
 * @return
 */
int *getNextVal(String target) {
    int *nextVal = calloc(target->length + 1, sizeof(int));
    *(nextVal + 1) = 0;
    int i = 1, j = 0;
    while (i < target->length) {
        if (j == 0 || charAt(target, i) == charAt(target, j)) {
            nextVal[++i] = ++j;
            if (charAt(target, i) == charAt(target, nextVal[i])) {
                nextVal[i] = nextVal[nextVal[i]];
            }
        } else {
            j = nextVal[j];
        }
    }
}

/**
 * 加强KMP
 * @param src
 * @param target
 * @return
 */
int enKMP(String src, String target) {
    int *next = getNextVal(target);
    int i = 1, j = 1;
    while (i <= src->length && j <= target->length) {
        if (j == 0 || charAt(target, i) == charAt(target, j)) {
            i++;
            j++;
        } else {
            j = *(next + j);
        }
    }
    if (j > target->length) {
        return i - target->length;
    } else {
        return 0;
    }
}






