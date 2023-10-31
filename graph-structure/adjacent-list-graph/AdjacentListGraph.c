//
// Created by Administrator on 2023/9/12.
//

#include "AdjacentListGraph.h"

typedef struct Edge {
    int weight;
    int vertexIndex;
    struct Edge *next;
} *Edge;

typedef struct Vertex {
    void *data;
    Edge firstEdge;
} *Vertex, *VertexList;

struct AdjacentListGraph {
    VertexList *vertexList;
    int vertexCount;
    int edgeCount;
    int size;

    int (*compare)(void *, void *);
};

/**
 * 构造函数
 * @param size
 * @param compare
 * @return
 */
AdjacentListGraph adjacentListGraphConstructor(int size, int (*compare)(void *, void *)) {
    AdjacentListGraph graph = malloc(sizeof(struct AdjacentListGraph));
    graph->vertexList = calloc(sizeof(Vertex), size);
    graph->vertexCount = 0;
    graph->edgeCount = 0;
    graph->size = size;
    graph->compare = compare;
    return graph;
}

static Vertex createVertex(void *data) {
    Vertex vertex = malloc(sizeof(struct Vertex));
    vertex->data = data;
    vertex->firstEdge = NULL;
    return vertex;
}

static Edge createEdge(int vertexIndex, Edge next) {
    Edge edge = malloc(sizeof(struct Edge));
    edge->vertexIndex = vertexIndex;
    edge->next = next;
    edge->weight = INFINITY;
    return edge;
}

static int getVertexIndex(AdjacentListGraph graph, void *data) {
    for (int i = 1; i <= graph->vertexCount; ++i) {
        if (graph->compare(graph->vertexList[i - 1]->data, data) == 0) {
            return i;
        }
    }
    return 0;
}

/**
 * 是否存在顶点
 * @param graph
 * @param data
 * @return
 */
bool hasVertex(AdjacentListGraph graph, void *data) {
    if (getVertexIndex(graph, data)) {
        return true;
    } else {
        return false;
    }
}

/**
 * 插入顶点
 * @param graph
 * @param data
 */
int insertVertex(AdjacentListGraph graph, void *data) {
    if (graph->vertexCount >= graph->size) {
        throw Error(FULL_ERROR, "图已满");
    }
    if (hasVertex(graph, data)) {
        throw Error(ELEMENT_EXISTS_ERROR, "顶点已存在");
    }
    Vertex vertex = createVertex(data);
    graph->vertexList[graph->vertexCount++] = vertex;
    return graph->vertexCount;
}

/**
 * 删除顶点
 * @param graph
 * @param vertex
 * @return
 */
void deleteVertex(AdjacentListGraph graph, void *vertex) {
    if (graph->vertexCount == 0) {
        throw Error(EMPTY_ERROR, "图为空");
    }
    int index = hasVertex(graph, vertex);
    if (index == 0) {
        throw Error(HAS_NO_ELEMENT_ERROR, "不存在该顶点");
    }
    //todo 删除顶点和边信息
}

static Vertex firstVertex(AdjacentListGraph graph, void *data) {
    int index = getVertexIndex(graph, data);
    if (index) {
        return graph->vertexList[graph->vertexList[index - 1]->firstEdge->vertexIndex - 1];
    } else {
        return NULL;
    }
}

static Vertex nextVertex(AdjacentListGraph graph, void *data, void *exceptData) {
    int index = getVertexIndex(graph, data);
    if (index) {
        Vertex vertex = graph->vertexList[index - 1];
        for (Edge edge = vertex->firstEdge; edge != NULL; edge = edge->next) {
            if (graph->compare(graph->vertexList[edge->vertexIndex - 1]->data, exceptData) == 0) {
                if (edge->next != NULL) {
                    return graph->vertexList[edge->next->vertexIndex - 1];
                }
            }
        }
        return NULL;
    } else {
        return NULL;
    }
}

/**
 * 是否存在边
 * @param graph
 * @param fromVertex
 * @param toVertex
 * @return
 */
bool hasEdge(AdjacentListGraph graph, void *fromVertex, void *toVertex) {
    int fromIndex = hasVertex(graph, fromVertex);
    int toIndex = hasVertex(graph, toVertex);
    for (Edge edge = graph->vertexList[fromIndex - 1]->firstEdge; edge != NULL; edge = edge->next) {
        if (edge->vertexIndex == toIndex) {
            return true;
        }
    }
    return false;
}

/**
 * 添加边
 * @param graph
 * @param fromVertex
 * @param toVertex
 */
void addEdge(AdjacentListGraph graph, void *fromVertex, void *toVertex) {
    if (hasEdge(graph, fromVertex, toVertex)) {
        throw Error(ELEMENT_EXISTS_ERROR, "边已存在");
    }
    int fromIndex = getVertexIndex(graph, fromVertex);
    int toIndex = getVertexIndex(graph, toVertex);
    if (!fromVertex) {
        fromIndex = insertVertex(graph, fromVertex);
    }
    if (!toVertex) {
        toIndex = insertVertex(graph, toVertex);
    }
    Vertex vertex = graph->vertexList[fromIndex - 1];
    vertex->firstEdge = createEdge(toIndex, vertex->firstEdge);
    graph->edgeCount++;
}

/**
 * 删除边
 * @param graph
 * @param fromVertex
 * @param toVertex
 * @return
 */
void removeEdge(AdjacentListGraph graph, void *fromVertex, void *toVertex) {
    if (!hasEdge(graph, fromVertex, toVertex)) {
        throw Error(HAS_NO_ELEMENT_ERROR, "边不存在");
    }
    int fromIndex = getVertexIndex(graph, fromVertex);
    int toIndex = getVertexIndex(graph, toVertex);
    Vertex vertex = graph->vertexList[fromIndex - 1];
    for (Edge *edge = &vertex->firstEdge; (*edge)->next != NULL; edge = &(*edge)->next) {
        if ((*edge)->vertexIndex == toIndex) {
            (*edge) = (*edge)->next;
            graph->edgeCount--;
            break;
        }
    }
}

/**
 * 设置权值
 * @param graph
 * @param fromVertex
 * @param toVertex
 * @param weight
 * @return
 */
bool setWeight(AdjacentListGraph graph, void *fromVertex, void *toVertex, int weight) {
    if (!hasEdge(graph, fromVertex, toVertex)) {
        throw Error(HAS_NO_ELEMENT_ERROR, "边不存在");
    }
    int fromIndex = getVertexIndex(graph, fromVertex);
    int toIndex = getVertexIndex(graph, toVertex);
    Vertex vertex = graph->vertexList[fromIndex - 1];
    for (Edge edge = vertex->firstEdge; edge != NULL; edge = edge->next) {
        if (edge->vertexIndex == toIndex) {
            edge->weight = weight;
            break;
        }
    }
}

/**
 * 获取权值
 * @param graph
 * @param fromVertex
 * @param toVertex
 * @param weight
 * @return
 */
int getWeight(AdjacentListGraph graph, void *fromVertex, void *toVertex, int weight) {
    if (!hasEdge(graph, fromVertex, toVertex)) {
        throw Error(HAS_NO_ELEMENT_ERROR, "边不存在");
    }
    int fromIndex = getVertexIndex(graph, fromVertex);
    int toIndex = getVertexIndex(graph, toVertex);
    Vertex vertex = graph->vertexList[fromIndex - 1];
    for (Edge edge = vertex->firstEdge; edge != NULL; edge = edge->next) {
        if (edge->vertexIndex == toIndex) {
            return edge->weight;
        }
    }
}

int getInDegree(AdjacentListGraph graph, void *vertex) {

}

int getOutDegree(AdjacentListGraph graph, void *vertex) {

}

bool isConnected(AdjacentListGraph graph) {

}

void BFS(AdjacentListGraph graph, bool isVisited[], LinkedQueue queue, LinkedQueue BFSDataQueue) {
    while (!linkedQueueIsEmpty(queue)) {
        Vertex vertex = linkedQueueDeQueue(queue);
        linkedQueueEnQueue(BFSDataQueue, vertex->data);
        isVisited[getVertexIndex(graph, vertex->data) - 1] = true;
        for (Vertex j = firstVertex(graph, vertex->data); j != NULL; j = nextVertex(graph, vertex->data, j->data)) {
            if (!isVisited[getVertexIndex(graph, j->data) - 1]) {
                linkedQueueEnQueue(queue, j);
            }
        }
    }
}

/**
 * 广度优先遍历
 * @param graph
 * @param BFSDataQueue
 */
void BFSTraverse(AdjacentListGraph graph, void *data, LinkedQueue BFSDataQueue) {
    bool *isVisited = calloc(graph->vertexCount, sizeof(bool));
    LinkedQueue queue = linkedQueueConstructor();
    linkedQueueEnQueue(queue, graph->vertexList[getVertexIndex(graph, data) - 1]);
    BFS(graph, isVisited, queue, BFSDataQueue);
    for (int i = 1; i <= graph->vertexCount; ++i) {
        if (!isVisited[i - 1]) {
            BFS(graph, isVisited, queue, BFSDataQueue);
        }
    }
}

void DFS(AdjacentListGraph graph, int vertexIndex, bool isVisited[], LinkedQueue DFSDataQueue) {
    Vertex vertex = graph->vertexList[vertexIndex - 1];
    linkedQueueEnQueue(DFSDataQueue, vertex->data);
    isVisited[vertexIndex - 1] = true;
    for (Vertex j = firstVertex(graph, vertex->data); j != NULL; j = nextVertex(graph, vertex->data, j->data)) {
        int index = getVertexIndex(graph, j->data);
        if (!isVisited[index - 1]) {
            DFS(graph, index, isVisited, DFSDataQueue);
        }
    }
}

/**
 * 深度优先遍历
 * @param graph
 * @param data
 * @param DFSDataQueue
 */
void DFSTraverse(AdjacentListGraph graph, void *data, LinkedQueue DFSDataQueue) {
    bool *isVisited = calloc(graph->vertexCount, sizeof(bool));
    int index = getVertexIndex(graph, data);
    DFS(graph, index, isVisited, DFSDataQueue);
    for (int i = 1; i <= graph->vertexCount; ++i) {
        if (!isVisited[i - 1]) {
            DFS(graph, i, isVisited, DFSDataQueue);
        }
    }
}

/**
 * Prim算法
 * @param graph
 * @return
 */
AdjacentListGraph Prim(AdjacentListGraph graph) {
    AdjacentListGraph MST = adjacentListGraphConstructor(graph->vertexCount, graph->compare);
    //是否加入最小生成树
    bool isJoin[graph->vertexCount];
    //路径长度
    int distance[graph->vertexCount];
    //路径前驱
    int path[graph->vertexCount];
    for (int i = 0; i < graph->vertexCount; ++i) {
        isJoin[i] = false;
        distance[i] = INFINITY;
        path[i] = -1;
    }
    while (MST->size != graph->vertexCount) {
        int fromIndex = -1, toIndex = -1, minDistance = 0;
        if (MST->vertexCount == 0) {
            toIndex = 1;
        } else {
            for (int i = 1; i <= graph->vertexCount; ++i) {
                if (isJoin[i - 1] == false && distance[i - 1] < minDistance) {
                    fromIndex = path[i - 1];
                    toIndex = i;
                    minDistance = distance[i - 1];
                }
            }
            if (toIndex == -1) {
                break;
            }
        }
        isJoin[toIndex - 1] = true;
        distance[toIndex - 1] = minDistance;
        path[toIndex - 1] = fromIndex;
        for (Edge edge = graph->vertexList[toIndex - 1]->firstEdge; edge != NULL; edge = edge->next) {
            if (edge->weight < distance[edge->vertexIndex - 1]) {
                distance[edge->vertexIndex - 1] = edge->weight;
                path[edge->vertexIndex - 1] = toIndex;
            }
        }
        insertVertex(MST, graph->vertexList[toIndex - 1]->data);
        MST->vertexCount++;
        addEdge(MST, graph->vertexList[fromIndex - 1]->data, graph->vertexList[toIndex - 1]->data);
        MST->edgeCount++;
        fromIndex = -1;
        toIndex = -1;
        minDistance = 0;
    }
    return MST;
}

/**
 * 克鲁斯卡尔算法
 * @param graph
 * @return
 */
AdjacentListGraph Kruskal(AdjacentListGraph graph) {
    AdjacentListGraph MST = adjacentListGraphConstructor(graph->vertexCount, graph->compare);
    PriorityQueue queue = priorityQueueConstructor(graph->compare);
    DisjointSet set = disjointSetConstructor(graph->vertexCount, graph->compare);
    for (int i = 1; i <= graph->vertexCount; ++i) {
        Vertex vertex = graph->vertexList[i - 1];
        disjointSetInsert(set, vertex->data);
        insertVertex(MST, vertex->data);
        for (Edge edge = graph->vertexList[i - 1]->firstEdge; edge != NULL; edge = edge->next) {
            int *tuple = calloc(3, sizeof(int));
            tuple[0] = i;
            tuple[1] = edge->vertexIndex;
            tuple[2] = edge->weight;
            priorityQueueEnQueue(queue, tuple);
        }
    }
    while (!priorityQueueIsEmpty(queue)) {
        int *tuple = priorityQueueDeQueue(queue);
        Vertex fromVertex = graph->vertexList[tuple[0] - 1];
        Vertex toVertex = graph->vertexList[tuple[1] - 1];
        int weight = tuple[2];
        if (graph->compare(disjointSetFind(set, fromVertex->data), disjointSetFind(set, toVertex->data)) != 0) {
            addEdge(MST, fromVertex->data, toVertex->data);
            setWeight(MST, fromVertex->data, toVertex->data, weight);
            disjointSetUnion(set, fromVertex, toVertex);
        }
    }
    return MST;
}

/**
 * BFS求无权图最短路径
 * @param graph
 * @param startVertex
 * @param endVertex
 * @param stack
 */
void BFSMinPath(AdjacentListGraph graph, void *startVertex, void *endVertex, SequenceStack stack) {
    //起始顶点到各个顶点的最短路径长度
    int distance[graph->vertexCount];
    //最短路径从哪个顶点过来
    int path[graph->vertexCount];
    bool isVisited[graph->vertexCount];
    for (int i = 0; i < graph->vertexCount; ++i) {
        distance[i] = INFINITY;
        path[i] = -1;
        isVisited[i] = false;
    }
    int startIndex = getVertexIndex(graph, startVertex);
    LinkedQueue queue = linkedQueueConstructor();
    distance[startIndex - 1] = 0;
    isVisited[startIndex - 1] = true;
    linkedQueueEnQueue(queue, startVertex);
    while (linkedQueueIsEmpty(queue)) {
        Vertex vertex = linkedQueueDeQueue(queue);
        for (Vertex near = firstVertex(graph, vertex->data); near != NULL; near = nextVertex(graph, vertex->data, near->data)) {
            int nearIndex = getVertexIndex(graph, near->data);
            if (!isVisited[nearIndex - 1]) {
                distance[nearIndex - 1] = distance[startIndex - 1] + 1;
                path[nearIndex - 1] = startIndex;
                isVisited[nearIndex - 1] = true;
                linkedQueueEnQueue(queue, near);
            }
        }
    }
    int minPath = getVertexIndex(graph, endVertex);
    while (path[minPath - 1] != -1) {
        sequenceStackPush(stack, graph->vertexList[minPath - 1]);
        minPath = path[minPath - 1];
    }
}

/**
 * 迪杰斯特拉算法
 * @param graph
 * @param startVertex
 * @param endVertex
 * @param stack
 */
void Dijkstra(AdjacentListGraph graph, void *startVertex, void *endVertex, SequenceStack stack) {
    int findCount = 0;
    //标记各顶点是否找到最短路径
    bool isFind[graph->vertexCount];
    //最短路径长度
    int distance[graph->vertexCount];
    //路径前驱
    int path[graph->vertexCount];
    for (int i = 0; i < graph->vertexCount; ++i) {
        isFind[i] = false;
        distance[i] = INFINITY;
        path[i] = -1;
    }
    while (findCount != graph->vertexCount) {
        int fromIndex = -1, toIndex = -1, minDistance = 0;
        if (findCount == 0) {
            toIndex = getVertexIndex(graph, startVertex);
        } else {
            for (int i = 1; i <= graph->vertexCount; ++i) {
                if (isFind[i - 1] == false && distance[i - 1] < minDistance) {
                    fromIndex = path[i - 1];
                    toIndex = i;
                    minDistance = distance[i - 1];
                }
            }
            if (toIndex == -1) {
                break;
            }
        }
        isFind[toIndex - 1] = true;
        distance[toIndex - 1] = minDistance;
        path[toIndex - 1] = fromIndex;
        for (Edge edge = graph->vertexList[toIndex - 1]->firstEdge; edge != NULL; edge = edge->next) {
            if (distance[toIndex - 1] + edge->weight < distance[edge->vertexIndex - 1]) {
                distance[edge->vertexIndex - 1] = distance[toIndex - 1] + edge->weight;
                path[edge->vertexIndex - 1] = toIndex;
            }
        }
        findCount++;
        fromIndex = -1;
        toIndex = -1;
        minDistance = 0;
    }
    int minPath = getVertexIndex(graph, endVertex);
    while (path[minPath - 1] != -1) {
        sequenceStackPush(stack, graph->vertexList[minPath - 1]);
        minPath = path[minPath - 1];
    }
}

void Floyd(AdjacentListGraph graph) {

}

/**
 * 拓扑排序
 * @param graph
 * @param queue
 */
void topologicalSort(AdjacentListGraph graph, LinkedQueue queue) {
    SequenceStack stack = sequenceStackConstructor(graph->vertexCount);
    int inDegreeList[graph->vertexCount];
    for (int i = 1; i <= graph->vertexCount; ++i) {
        inDegreeList[i - 1] = getInDegree(graph, graph->vertexList[i - 1]->data);
        if (inDegreeList[i - 1] == 0) {
            sequenceStackPush(stack, graph->vertexList[i - 1]);
        }
    }
    while (!sequenceStackIsEmpty(stack)) {
        Vertex vertex = sequenceStackPop(stack);
        linkedQueueEnQueue(queue, vertex->data);
        for (Edge edge = vertex->firstEdge; edge != NULL; edge = edge->next) {
            if (--inDegreeList[edge->vertexIndex - 1] == 0) {
                sequenceStackPush(stack, graph->vertexList[edge->vertexIndex - 1]);
            }
        }
    }
}

void DFSInTopological(AdjacentListGraph graph, int index, int isVisited[], LinkedQueue queue) {
    isVisited[index - 1] = 2;
    Vertex vertex = graph->vertexList[index - 1];
    for (Edge edge = vertex->firstEdge; edge != NULL; edge = edge->next) {
        if (isVisited[edge->vertexIndex - 1] == 0) {
            DFSInTopological(graph, edge->vertexIndex, isVisited, queue);
        }
        if (isVisited[edge->vertexIndex - 1] == 2) {
            throw Error(CYCLIC_GRAPH_ERROR, "图中含有环，逆拓扑排序失败");
        }
    }
    isVisited[index - 1] = 1;
    linkedQueueEnQueue(queue, vertex->data);
}

/**
 * 深度优先算法求逆拓扑排序
 * @param graph
 * @param queue
 */
void DFSInTopologicalSort(AdjacentListGraph graph, LinkedQueue queue) {
    int *isVisited = calloc(graph->vertexCount, sizeof(bool));
    for (int i = 1; i <= graph->vertexCount; ++i) {
        if (isVisited[i - 1] == 0) {
            DFSInTopological(graph, i, isVisited, queue);
        }
    }
}

void criticalPath(AdjacentListGraph graph) {

}
