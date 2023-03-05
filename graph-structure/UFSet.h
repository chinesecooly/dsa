//
// Created by Administrator on 2022/3/30.
//

#ifndef INC_2023_UFSET_H
#define INC_2023_UFSET_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct UFSet * UFSet;

UFSet ufSetConstruct(int len);
void ufSetFinalize(UFSet set);
int ufSetFind(UFSet set,int x);
bool ufSetUnion(UFSet set, int root1, int root2);

#endif //INC_2023_UFSET_H
