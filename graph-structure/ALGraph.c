//
// Created by Administrator on 2022/3/30.
//

#include "ALGraph.h"

struct EdgeNode {
    int vex;
    EdgeType data;
    struct EdgeNode *next;
};

struct VexNode {
    VertexType data;
    EdgeList edgeList;
};

struct ALGraph{
    VexList vexList;
    int vexNum;
    int edgeNum;
};
