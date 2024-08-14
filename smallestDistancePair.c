#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int countPairs(int* nums, int numsSize, int mid) {
    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        int j = i + 1;
        while (j < numsSize && nums[j] - nums[i] <= mid) {
            j++;
        }
        count += j - i - 1;
    }
    return count;
}

int smallestDistancePair(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), compare);

    int low = 0;
    int high = nums[numsSize - 1] - nums[0];
    
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (countPairs(nums, numsSize, mid) < k) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    
    return low;
}
