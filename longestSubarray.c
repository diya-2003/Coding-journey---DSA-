int longestSubarray(int* nums, int numsSize) {
    // Step 1: Find the maximum element in the array
    int maxVal = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > maxVal) {
            maxVal = nums[i];
        }
    }
    
    // Step 2: Find the longest contiguous subarray where all elements are maxVal
    int maxLength = 0;
    int currentLength = 0;
    
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == maxVal) {
            currentLength++;
            if (currentLength > maxLength) {
                maxLength = currentLength;
            }
        } else {
            currentLength = 0;  // Reset the count when encountering a different value
        }
    }
    
    return maxLength;
}
