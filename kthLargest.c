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
        smallest = left;    }
    if (right < size && heap[right] < heap[smallest]) {
        smallest = right;    }
    if (smallest != idx) {
        int temp = heap[idx];
        heap[idx] = heap[smallest];
        heap[smallest] = temp;
        heapifyDown(heap, smallest, size);    }}
void heapifyUp(int* heap, int idx) {
    int parent = (idx - 1) / 2;
    if (idx > 0 && heap[idx] < heap[parent]) {
        int temp = heap[idx];
        heap[idx] = heap[parent];
        heap[parent] = temp;
        heapifyUp(heap, parent);    }}
KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    KthLargest* obj = (KthLargest*)malloc(sizeof(KthLargest));
    obj->heap = (int*)malloc(sizeof(int) * k);
    obj->size = 0;
    obj->capacity = k;
    for (int i = 0; i < numsSize; i++) {
        kthLargestAdd(obj, nums[i]);    }
    return obj;}
int kthLargestAdd(KthLargest* obj, int val) {
    if (obj->size < obj->capacity) {
        obj->heap[obj->size++] = val;
        heapifyUp(obj->heap, obj->size - 1);
    } else if (val > obj->heap[0]) {
        obj->heap[0] = val;
        heapifyDown(obj->heap, 0, obj->size);    }
    return obj->heap[0];}
void kthLargestFree(KthLargest* obj) {
    free(obj->heap);
    free(obj);}
/*	Author   : Diya Maity
	Date     : Friday, August 12, 2024, 04:40 PM	
	LinkedIn : https://www.linkedin.com/in/diyamity
	GitHub   : https://github.com/diya-2003
	LeetCode : https://leetcode.com/u/diyamaity        		*/
