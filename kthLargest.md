# Intuition
When asked to find the kth largest element in a stream of numbers, the first idea that comes to mind is to maintain the k largest elements seen so far. The smallest of these elements will be the kth largest. This can be efficiently managed using a min-heap, which allows us to quickly identify and update the kth largest element as new numbers are added.

# Approach
We use a min-heap (priority queue) of size `k` to store the k largest elements from the stream. The smallest element in this heap is the kth largest in the stream. For each new element added:
1. If the heap has fewer than `k` elements, we add the new element.
2. If the heap is full, we compare the new element to the smallest element in the heap (the root). If the new element is larger, we replace the root with this new element and reheapify.

This approach ensures that the kth largest element is always at the root of the heap.

# Complexity
- **Time complexity:**  
  - Initial construction: \(O(n \log k)\), where `n` is the number of elements in the initial stream.
  - For each `add` operation: \(O(\log k)\).

- **Space complexity:**  
  - \(O(k)\) for storing the k largest elements.

# Code
```c
#include <stdlib.h>

typedef struct {
    int* heap;
    int size;
    int capacity;
} KthLargest;

void heapifyDown(int* heap, int idx, int size) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < size && heap[left] < heap[smallest]) {
        smallest = left;
    }

    if (right < size && heap[right] < heap[smallest]) {
        smallest = right;
    }

    if (smallest != idx) {
        int temp = heap[idx];
        heap[idx] = heap[smallest];
        heap[smallest] = temp;
        heapifyDown(heap, smallest, size);
    }
}

void heapifyUp(int* heap, int idx) {
    int parent = (idx - 1) / 2;
    if (idx > 0 && heap[idx] < heap[parent]) {
        int temp = heap[idx];
        heap[idx] = heap[parent];
        heap[parent] = temp;
        heapifyUp(heap, parent);
    }
}

KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    KthLargest* obj = (KthLargest*)malloc(sizeof(KthLargest));
    obj->heap = (int*)malloc(sizeof(int) * k);
    obj->size = 0;
    obj->capacity = k;

    for (int i = 0; i < numsSize; i++) {
        kthLargestAdd(obj, nums[i]);
    }

    return obj;
}

int kthLargestAdd(KthLargest* obj, int val) {
    if (obj->size < obj->capacity) {
        obj->heap[obj->size++] = val;
        heapifyUp(obj->heap, obj->size - 1);
    } else if (val > obj->heap[0]) {
        obj->heap[0] = val;
        heapifyDown(obj->heap, 0, obj->size);
    }

    return obj->heap[0];
}

void kthLargestFree(KthLargest* obj) {
    free(obj->heap);
    free(obj);
}
/*	Author   : Diya Maity
	Date     : Friday, August 12, 2024, 04:40 PM	
	LinkedIn : https://www.linkedin.com/in/diyamity
	GitHub   : https://github.com/diya-2003
	LeetCode : https://leetcode.com/u/diyamaity        		*/
```
