//
// Created by Administrator on 2023/9/9.
//

#include "Comparable.h"

int intComp(void *a, void *b) {
    int sub = *((int *) a) - *((int *) b);
    if (sub > 0) {
        return 1;
    } else if (sub < 0) {
        return -1;
    } else {
        return 0;
    }
}

int floatComp(void *a, void *b) {
    float sub = *((float *) a) - *((float *) b);
    if (sub > 0) {
        return 1;
    } else if (sub < 0) {
        return -1;
    } else {
        return 0;
    }
}

int doubleComp(void *a, void *b) {
    double sub = *((double *) a) - *((double *) b);
    if (sub > 0) {
        return 1;
    } else if (sub < 0) {
        return -1;
    } else {
        return 0;
    }
}

int charComp(void *a, void *b) {
    char sub = *((char *) a) - *((char *) b);
    if (sub > 0) {
        return 1;
    } else if (sub < 0) {
        return -1;
    } else {
        return 0;
    }
}

int (*intCompare)(void *, void *) =intComp;

int (*floatCompare)(void *, void *) =floatComp;

int (*doubleCompare)(void *, void *) =doubleComp;

int (*charCompare)(void *, void *) =charComp;