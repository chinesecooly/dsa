//
// Created by Administrator on 2022/3/30.
//

#include "MGraph.h"

struct MGraph {
    VertexType *vex;
    EdgeType **edge;
    int vexNum;
    int edgeNum;
};

static void visit(int vex) {

}

static void BFS(MGraph graph, int vex, bool isVisited[]) {
    LinkedQueue queue = linkedQueueConstructor();
    visit(vex);
    isVisited[vex] = true;
//    enQueue(queue,  vex);
    for (; !linkedQueueIsEmpty(queue);) {
//        vex=deQueue(queue);
        for (int i = firstNeighbor(graph, vex); i >= 0; i = nextNeighbor(graph, vex, i)) {
            if (!isVisited[i]) {
                visit(i);
                isVisited[i] = true;
//                enQueue(queue,i);
            }
        }
    }
}

void BFSTraverse(MGraph graph) {
    bool isVisited[graph->vexNum];
    for (int i = 0; i < graph->vexNum; ++i) {
        isVisited[i] = false;
    }
    for (int i = 0; i < graph->vexNum; ++i) {
        if (!isVisited[i]) {
            BFS(graph, i, isVisited);
        }
    }
}

static void DFS(MGraph graph, int vex, bool isVisited[]) {
    visit(vex);
    isVisited[vex] = true;
    for (int i = firstNeighbor(graph, vex); i >= 0; i = nextNeighbor(graph, vex, i)) {
        if (isVisited[i]) {
            DFS(graph, i, isVisited);
        }
    }
}

void DFSTraverse(MGraph graph) {
    bool isVisited[graph->vexNum];
    for (int i = 0; i < graph->vexNum; ++i) {
        isVisited[i] = false;
    }
    for (int i = 0; i < graph->vexNum; ++i) {
        if (!isVisited[i]) {
            DFS(graph, i, isVisited);
        }
    }
}


int firstNeighbor(MGraph graph, int vex) {

}

int nextNeighbor(MGraph graph, int vex, int Neighbor) {

}


