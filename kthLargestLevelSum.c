#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_HEAP_SIZE 100000

struct QueueNode {
    struct TreeNode* node;
    struct QueueNode* next;
};
struct TreeNode* newTreeNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}
struct QueueNode* newQueueNode(struct TreeNode* node) {
    struct QueueNode* qNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    qNode->node = node;
    qNode->next = NULL;
    return qNode;
}
struct Queue {
    struct QueueNode *front, *rear;
};

// Helper function to create a queue.
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Helper function to enqueue a tree node into the queue.
void enqueue(struct Queue* q, struct TreeNode* node) {
    struct QueueNode* temp = newQueueNode(node);
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

// Helper function to dequeue a tree node from the queue.
struct TreeNode* dequeue(struct Queue* q) {
    if (q->front == NULL)
        return NULL;

    struct QueueNode* temp = q->front;
    struct TreeNode* node = temp->node;
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    return node;
}

// Min-heap for keeping the k largest sums.
void heapify(long long heap[], int size, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;

    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        long long temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;

        heapify(heap, size, smallest);
    }
}

// Function to insert into the min-heap.
void insertHeap(long long heap[], int* heapSize, long long value, int k) {
    if (*heapSize < k) {
        heap[*heapSize] = value;
        (*heapSize)++;
        for (int i = (*heapSize) / 2 - 1; i >= 0; i--) {
            heapify(heap, *heapSize, i);
        }
    } else if (value > heap[0]) {
        heap[0] = value;
        heapify(heap, *heapSize, 0);
    }
}

// Main function to calculate the kth largest level sum.
long long kthLargestLevelSum(struct TreeNode* root, int k) {
    if (root == NULL) return -1;

    // Create a queue for BFS.
    struct Queue* q = createQueue();
    enqueue(q, root);
    long long heap[MAX_HEAP_SIZE];
    int heapSize = 0;
    while (q->front != NULL) {
        int levelSize = 0;
        long long levelSum = 0;
        struct QueueNode* temp = q->front;
        while (temp != NULL) {
            levelSize++;
            temp = temp->next;
        }
        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* currentNode = dequeue(q);
            levelSum += currentNode->val;
            if (currentNode->left != NULL) enqueue(q, currentNode->left);
            if (currentNode->right != NULL) enqueue(q, currentNode->right);
        }
        insertHeap(heap, &heapSize, levelSum, k);
    }
    if (heapSize < k) {
        return -1;
    }
    return heap[0];
}
