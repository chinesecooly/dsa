//
// Created by Administrator on 2023/9/18.
//

#include "AcrossLinkerGraph.h"

typedef struct AcrossLinkerGraphVertex {
    void *data;
    int tailVex; //弧头顶点位置
    int headVex; //弧尾顶点位置
    int headLink; //弧头相同的下一条弧
    int tailLink; //弧尾相同的下一条弧
} AcrossLinkerGraphVertex;

typedef struct AcrossLinkerGraphEdge {
    void *data;
    AcrossLinkerGraphVertex *firstIn; //以该顶点为弧头的第一个弧顶点
    AcrossLinkerGraphVertex *firstOut; //以该顶点为为弧尾的第一个弧顶点
} *VexList;

struct AcrossLinkerGraph {
    VexList vexList;
    int vexNum;
    int arcNum;
} *OLGraph;
