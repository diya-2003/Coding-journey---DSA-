typedef struct {
    int value;
    int listIdx;
    int elemIdx;
} HeapNode;
int cmp(const void* a, const void* b) {
    return ((HeapNode*)a)->value - ((HeapNode*)b)->value;
}
void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}
void heapifyDown(HeapNode heap[], int size, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    if (left < size && cmp(&heap[left], &heap[smallest]) < 0) {
        smallest = left;
    }
    if (right < size && cmp(&heap[right], &heap[smallest]) < 0) {
        smallest = right;
    }
    if (smallest != idx) {
        swap(&heap[idx], &heap[smallest]);
        heapifyDown(heap, size, smallest);
    }
}
void heapifyUp(HeapNode heap[], int idx) {
    int parent = (idx - 1) / 2;
    if (parent >= 0 && cmp(&heap[idx], &heap[parent]) < 0) {
        swap(&heap[idx], &heap[parent]);
        heapifyUp(heap, parent);
    }
}
HeapNode extractMin(HeapNode heap[], int* size) {
    HeapNode minNode = heap[0];
    heap[0] = heap[--(*size)];
    heapifyDown(heap, *size, 0);
    return minNode;
}
void insertHeap(HeapNode heap[], int* size, HeapNode node) {
    heap[(*size)++] = node;
    heapifyUp(heap, *size - 1);
}
int* smallestRange(int** nums, int numsSize, int* numsColSize, int* returnSize) {
    HeapNode* heap = (HeapNode*)malloc(numsSize * sizeof(HeapNode));
    int heapSize = 0;
    int curMax = INT_MIN;
    int* result = (int*)malloc(2 * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        HeapNode node = {nums[i][0], i, 0};
        insertHeap(heap, &heapSize, node);
        if (nums[i][0] > curMax) {
            curMax = nums[i][0];
        }
    }
    int rangeMin = 0, rangeMax = INT_MAX;
    while (heapSize == numsSize) {
        HeapNode minNode = extractMin(heap, &heapSize);
        int curMin = minNode.value;
        int listIdx = minNode.listIdx;
        int elemIdx = minNode.elemIdx;
        if (curMax - curMin < rangeMax - rangeMin || 
           (curMax - curMin == rangeMax - rangeMin && curMin < rangeMin)) {
            rangeMin = curMin;
            rangeMax = curMax;
        }
        if (elemIdx + 1 < numsColSize[listIdx]) {
            HeapNode nextNode = {nums[listIdx][elemIdx + 1], listIdx, elemIdx + 1};
            insertHeap(heap, &heapSize, nextNode);
            if (nums[listIdx][elemIdx + 1] > curMax) {
                curMax = nums[listIdx][elemIdx + 1];
            }
        } else {
            break;
        }
    }
    result[0] = rangeMin;
    result[1] = rangeMax;
    *returnSize = 2;
    
    free(heap);
    return result;
}
