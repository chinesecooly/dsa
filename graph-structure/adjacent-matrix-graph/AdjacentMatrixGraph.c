//
// Created by Administrator on 2023/9/12.
//

#include "AdjacentMatrixGraph.h"

struct AdjacentMatrixGraph {
    void **vertexList;
    bool **edgeMatrix;
    int vertexCount;
    int edgeCount;
    int size;
};


AdjacentMatrixGraph adjacentMatrixGraphConstructor(int size) {
    AdjacentMatrixGraph graph = malloc(sizeof(struct AdjacentMatrixGraph));
    graph->vertexList = calloc(size, sizeof(bool *));
    *(graph->edgeMatrix + 0) = calloc(size * size, sizeof(bool));
    for (int i = 1; i < size; ++i) {
        *(graph->edgeMatrix + i) = *(graph->edgeMatrix + 0) + i * size;
    }
    graph->vertexCount = 0;
    graph->edgeCount = 0;
    graph->size = size;
    return graph;
}


