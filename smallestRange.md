
### Intuition
The problem asks us to find the smallest range that includes at least one number from each of the `k` sorted lists. My first thought was to use a min-heap (priority queue) to efficiently keep track of the smallest element across all lists. By always looking at the minimum element and trying to move the next element from the same list, we can shrink the range. The challenge lies in keeping track of the maximum number in the current range, so that the range can be updated dynamically.

### Approach
1. **Initialize a min-heap**: We store the first element from each list in a heap. Each entry in the heap contains the value, the list index, and the element index from that list.
2. **Track the maximum element**: As we extract the minimum element from the heap, we track the maximum number encountered so far to compute the range `[min, max]`.
3. **Update the range**: Every time a new minimum element is extracted from the heap, we compare the current range to the smallest found so far. If the new range is smaller, update it.
4. **Replace the extracted element**: After extracting the minimum, we insert the next element from the same list into the heap, and update the maximum if the newly inserted element is larger than the current maximum.
5. **Termination**: When any list is exhausted, we stop because we can no longer form a valid range that covers all lists.

### Complexity
- **Time complexity**: The time complexity is \(O(n \cdot \log k)\), where `n` is the total number of elements across all lists and `k` is the number of lists. Insertion and extraction from the heap take \(O(\log k)\), and we do this for each element.
- **Space complexity**: The space complexity is \(O(k)\), where `k` is the number of lists, since the heap stores one element from each list at a time.

### Code
```c
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
/*	Author   : Pankaj Mondal
	Date     : Sunday, October 13, 2024, 08:04 PM
	LinkedIn : https://www.linkedin.com/in/buroush
	GitHub   : https://github.com/Buroush
	LeetCode : https://leetcode.com/Buroush        		*/
```

>
> “আপনি সমুদ্র পার হতে পারবেন না শুধুমাত্র জলের দিকে দাঁড়িয়ে তাকিয়ে থাকলে” ~ রবীন্দ্রনাথ ঠাকুর

> “You cannot cross the sea merely by standing and staring at the water.” ~ Rabindranath Tagore
