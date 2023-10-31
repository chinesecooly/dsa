//
// Created by Administrator on 2023/9/12.
//

#include "AdjacentMatrixGraph.h"

struct AdjacentMatrixGraph {
    void **vertexList;
    int **edgeMatrix;
    int vertexCount;
    int edgeCount;
    int size;

    int (*compare)(void *, void *);
};

AdjacentMatrixGraph adjacentMatrixGraphConstructor(int size, int (*vertexCompare)(void *, void *)) {
    AdjacentMatrixGraph graph = malloc(sizeof(struct AdjacentMatrixGraph));
    graph->vertexList = calloc(size, sizeof(void *));
    graph->edgeMatrix = calloc(size, sizeof(int *));
    *(graph->edgeMatrix + 0) = calloc(size * size, sizeof(int));
    for (int i = 1; i < size; ++i) {
        *(graph->edgeMatrix + i) = *(graph->edgeMatrix + 0) + i * size;
    }
    graph->vertexCount = 0;
    graph->edgeCount = 0;
    graph->size = size;
    graph->compare = vertexCompare;
    return graph;
}

/**
 * 是否存在顶点
 * @param graph
 * @param vertex
 * @return
 */
int hasVertex(AdjacentMatrixGraph graph, void *vertex) {
    for (int i = 1; i <= graph->vertexCount; ++i) {
        if (graph->compare(graph->vertexList[i - 1], vertex) == 0) {
            return i;
        }
    }
    return 0;
}

/**
 * 插入顶点
 * @param graph
 * @param vertex
 */
void insertVertex(AdjacentMatrixGraph graph, void *vertex) {
    if (graph->vertexCount >= graph->size) {
        throw Error(FULL_ERROR, "图已满");
    }
    if (hasVertex(graph, vertex)) {
        throw Error(ELEMENT_EXISTS_ERROR, "顶点已存在");
    }
    graph->vertexList[graph->vertexCount++] = vertex;
}

/**
 * 删除顶点
 * @param graph
 * @param vertex
 * @return
 */
void deleteVertex(AdjacentMatrixGraph graph, void *vertex) {
    if (graph->vertexCount == 0) {
        throw Error(EMPTY_ERROR, "图为空");
    }
    int index = hasVertex(graph, vertex);
    if (index == 0) {
        throw Error(HAS_NO_ELEMENT_ERROR, "不存在该顶点");
    }
    //todo 删除顶点和边信息
}

/**
 * 是否存在边
 * @param graph
 * @param fromVertex
 * @param toVertex
 * @return
 */
bool hasEdge(AdjacentMatrixGraph graph, void *fromVertex, void *toVertex) {
    int fromIndex = hasVertex(graph, fromVertex);
    int toIndex = hasVertex(graph, toVertex);
    return graph->edgeMatrix[fromIndex - 1][toIndex - 1];
}

/**
 * 添加边
 * @param graph
 * @param fromVertex
 * @param toVertex
 * @return
 */
bool addEdge(AdjacentMatrixGraph graph, void *fromVertex, void *toVertex) {
    if (hasEdge(graph, fromVertex, toVertex)) {
        throw Error(ELEMENT_EXISTS_ERROR, "边已存在");
    }

}

/**
 * 删除边
 * @param graph
 * @param fromVertex
 * @param toVertex
 * @return
 */
bool removeEdge(AdjacentMatrixGraph graph, void *fromVertex, void *toVertex) {

}

/**
 * 设置权值
 * @param graph
 * @param fromVertex
 * @param toVertex
 * @param weight
 * @return
 */
bool setWeight(AdjacentMatrixGraph graph, void *fromVertex, void *toVertex, int weight) {

}

int getWeight(AdjacentMatrixGraph graph, void *fromVertex, void *toVertex, int weight) {

}

int getInDegree(AdjacentMatrixGraph graph, void *vertex) {

}

int getOutDegree(AdjacentMatrixGraph graph, void *vertex) {

}

bool isConnected(AdjacentMatrixGraph graph) {

}



