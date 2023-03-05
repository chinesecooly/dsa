//
// Created by Administrator on 2022/3/31.
//

#include "AMLGraph.h"

struct EdgeNode {
    bool mark; //是否被搜搜过
    int iVex; //该边依附的一个顶点位置
    int jVex; //该边依附的另一个顶点位置
    int iLink; //下一个依附顶点iVex的边
    int jLink; //下一个依附顶点jVex的边
};

struct VexNode {
    VexType data;
    EdgeNode *firstEdge; //第一个依附该顶点的边
};

struct AMLGraph {
    VexList vexList;
    int vexNum;
    int edgeNum;
};
