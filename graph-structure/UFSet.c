//
// Created by Administrator on 2022/3/30.
//

#include "UFSet.h"

struct UFSet {
    int * nodes;
};

UFSet ufSetConstruct(int len) {
    UFSet set = malloc(sizeof(struct UFSet));
    set->nodes = calloc(sizeof(int), len);
    for (int i = 0; i < len; ++i) {
        *(set->nodes + i) = -1;
    }
    return set;
}

void ufSetFinalize(UFSet set) {
    free(set->nodes);
    free(set);
}

int ufSetFind(UFSet set, int x) {
    for (; *(set->nodes + x) >= 0;) {
        x = *(set->nodes + x);
    }
    return x;
}

bool ufSetUnion(UFSet set, int root1, int root2) {
    if (ufSetFind(set, root1) == ufSetFind(set, root2)) {
        return false;
    } else {
        *(set->nodes + root2) = *(set->nodes + root1);
        return true;
    }
}


