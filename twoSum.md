Intuition

This problem seems like a classic use case for a brute-force approach. We need to find two numbers in the given array that add up to the target. The brute-force method involves checking every pair of numbers until we find the desired sum.

Approach

The approach here is simple: iterate through the array and for each element, iterate through the rest of the array to find the pair that adds up to the target. If found, return the indices of those elements. If no such pair exists, return NULL.

Complexity

Time complexity: O(n2)O(n2), where nn is the size of the input array. This is because we have nested loops, resulting in checking every pair of numbers.
Space complexity: O(1)O(1), excluding the space required for the output array since it's a constant size.
Code

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int* result = (int*)malloc(2 * sizeof(int));
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}