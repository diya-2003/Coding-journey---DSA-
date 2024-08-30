#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_HEAP_SIZE 10000

typedef struct {
    int dist;
    int node;
} MinHeapNode;

typedef struct {
    MinHeapNode *array;
    int size;
} MinHeap;

typedef struct {
    int u, v, weight;
} Edge;

typedef struct {
    int **array;
    int size;
} AdjList;

typedef struct {
    int dist;
    int mod_id;
} BFSResult;

// Create a Min-Heap with a given maximum size
MinHeap* createMinHeap(int maxSize) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->array = (MinHeapNode*)malloc(maxSize * sizeof(MinHeapNode));
    heap->size = 0;
    return heap;
}

// Swap two nodes in the Min-Heap
void swapMinHeapNode(MinHeapNode* a, MinHeapNode* b) {
    MinHeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify the Min-Heap
void minHeapify(MinHeap* heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < heap->size && heap->array[left].dist < heap->array[smallest].dist) {
        smallest = left;
    }
    if (right < heap->size && heap->array[right].dist < heap->array[smallest].dist) {
        smallest = right;
    }
    if (smallest != idx) {
        swapMinHeapNode(&heap->array[smallest], &heap->array[idx]);
        minHeapify(heap, smallest);
    }
}

// Extract the minimum node from the Min-Heap
MinHeapNode extractMin(MinHeap* heap) {
    if (heap->size == 0) {
        return (MinHeapNode){ INT_MAX, -1 };
    }

    MinHeapNode root = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    --heap->size;

    minHeapify(heap, 0);

    return root;
}

// Insert a new node into the Min-Heap
void insertMinHeap(MinHeap* heap, int dist, int node) {
    ++heap->size;
    int i = heap->size - 1;
    heap->array[i].dist = dist;
    heap->array[i].node = node;

    while (i && heap->array[i].dist < heap->array[(i - 1) / 2].dist) {
        swapMinHeapNode(&heap->array[i], &heap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Create an adjacency list
AdjList* createAdjList(int n, int edgesSize) {
    AdjList* list = (AdjList*)malloc(n * sizeof(AdjList));
    for (int i = 0; i < n; ++i) {
        list[i].array = (int**)malloc(edgesSize * sizeof(int*));
        list[i].size = 0;
    }
    return list;
}

// Add an edge to the adjacency list
void addEdge(AdjList* adjList, int u, int v, int edgeIndex) {
    adjList[u].array[adjList[u].size] = (int*)malloc(2 * sizeof(int));
    adjList[u].array[adjList[u].size][0] = v;
    adjList[u].array[adjList[u].size][1] = edgeIndex;
    adjList[u].size++;
}

// Free the memory allocated for the adjacency list
void freeAdjList(AdjList* list, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < list[i].size; ++j) {
            free(list[i].array[j]);
        }
        free(list[i].array);
    }
    free(list);
}

// Free the memory allocated for the Min-Heap
void freeMinHeap(MinHeap* heap) {
    free(heap->array);
    free(heap);
}

// Perform BFS with potential modifications
BFSResult bfs(AdjList* adjList, Edge* edges, int n, int source, int dest, bool modify) {
    MinHeap* heap = createMinHeap(MAX_HEAP_SIZE);
    int* dist = (int*)malloc(n * sizeof(int));
    int* mod_id = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; ++i) {
        dist[i] = INT_MAX;
        mod_id[i] = INT_MAX;
    }
    insertMinHeap(heap, 0, source);
    dist[source] = 0;

    while (heap->size != 0) {
        MinHeapNode minNode = extractMin(heap);
        int d = minNode.dist;
        int i = minNode.node;

        if (d != dist[i]) {
            continue;
        }

        for (int j = 0; j < adjList[i].size; ++j) {
            int v = adjList[i].array[j][0];
            int edge_id = adjList[i].array[j][1];
            int w = edges[edge_id].weight;

            if (modify || w != -1) {
                int newDist = d + (w > 0 ? w : 1);
                if (dist[v] > newDist) {
                    mod_id[v] = (w == -1) ? edge_id : mod_id[i];
                    dist[v] = newDist;
                    insertMinHeap(heap, dist[v], v);
                }
            }
        }
    }

    BFSResult result = { dist[dest], mod_id[dest] };
    free(dist);
    free(mod_id);
    freeMinHeap(heap);

    return result;
}

// Modify graph edges to achieve the target shortest path
int** modifiedGraphEdges(int n, int** edges, int edgesSize, int* edgesColSize, int source, int destination, int target, int* returnSize, int** returnColumnSizes) {
    Edge* edgeArray = (Edge*)malloc(edgesSize * sizeof(Edge));
    AdjList* adjList = createAdjList(n, edgesSize);

    for (int i = 0; i < edgesSize; ++i) {
        edgeArray[i].u = edges[i][0];
        edgeArray[i].v = edges[i][1];
        edgeArray[i].weight = edges[i][2];
        addEdge(adjList, edgeArray[i].u, edgeArray[i].v, i);
        addEdge(adjList, edgeArray[i].v, edgeArray[i].u, i);
    }

    BFSResult distMod = bfs(adjList, edgeArray, n, source, destination, false);

    if (distMod.dist < target) {
        free(edgeArray);
        freeAdjList(adjList, n);
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    while (true) {
        distMod = bfs(adjList, edgeArray, n, source, destination, true);

        if (distMod.dist > target) {
            free(edgeArray);
            freeAdjList(adjList, n);
            *returnSize = 0;
            *returnColumnSizes = NULL;
            return NULL;
        }

        if (distMod.dist == target) {
            break;
        }

        edgeArray[distMod.mod_id].weight = 1 + target - distMod.dist;
    }

    for (int i = 0; i < edgesSize; ++i) {
        if (edgeArray[i].weight == -1) {
            edgeArray[i].weight = 1;
        }
        edges[i][2] = edgeArray[i].weight;
    }

    free(edgeArray);
    freeAdjList(adjList, n);

    *returnSize = edgesSize;
    *returnColumnSizes = (int*)malloc(edgesSize * sizeof(int));

    for (int i = 0; i < edgesSize; ++i) {
        (*returnColumnSizes)[i] = 3;
    }

    return edges;
}
