//
// Created by Administrator on 2023/9/12.
//

#include "AdjacentListGraph.h"

typedef struct AdjacentListGraphEdge {
    int Vertex;
    struct AdjacentListGraphEdge *next;
} AdjacentListGraphEdge;

typedef struct AdjacentListGraphVertex {
    void *data;
    struct AdjacentListGraphEdge *edge;
} AdjacentListGraphNode, *AdjacentListGraphVertexList;

struct AdjacentListGraph {
    AdjacentListGraphVertexList list;
    int vertexCount;
    int edgeCount;
};

