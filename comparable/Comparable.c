//
// Created by Administrator on 2023/9/9.
//

#include "Comparable.h"

int intComp(void *a, void *b) {
    return *((int *) a) - *((int *) b) > 0;
}

int floatComp(void *a, void *b) {
    return *((float *) a) - *((float *) b) > 0;
}

int doubleComp(void *a, void *b) {
    return *((double *) a) - *((double *) b) > 0;
}

int charComp(void *a, void *b) {
    return *((char *) a) - *((char *) b) > 0;
}

int (*intCompare)(void *, void *) =intComp;

int (*floatCompare)(void *, void *) =floatComp;

int (*doubleCompare)(void *, void *) =doubleComp;

int (*charCompare)(void *, void *) =charComp;