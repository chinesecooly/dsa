//
// Created by Administrator on 2022/3/30.
//

#ifndef INC_2023_MGRAPH_H
#define INC_2023_MGRAPH_H
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "../constrained-linear-list/LinkQueue.h"

typedef void * VertexType;
typedef void * EdgeType;

typedef struct MGraph *MGraph;
void BFSTraverse(MGraph graph);
int firstNeighbor(MGraph graph,int vex);
int nextNeighbor(MGraph graph,int vex,int Neighbor);

#endif //INC_2023_MGRAPH_H
