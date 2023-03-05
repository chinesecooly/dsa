//
// Created by Administrator on 2022/3/31.
//

#include "OLGraph.h"

struct ArcNode{
    ArcType data;
    int tailVex; //弧头顶点位置
    int headVex; //弧尾顶点位置
    int headLink; //弧头相同的下一条弧
    int tailLink; //弧尾相同的下一条弧
};

struct VexNode {
    VertexType data;
    ArcNode * firstIn; //以该顶点为弧头的第一个弧顶点
    ArcNode * firstOut; //以该顶点为为弧尾的第一个弧顶点
};

struct OLGraph{
    VexList vexList;
    int vexNum;
    int arcNum;
};
