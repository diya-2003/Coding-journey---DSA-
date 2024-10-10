int maxWidthRamp(int* nums, int numsSize) {
    int stack[numsSize], max = 0, j = 0;

    // Build a decreasing stack of indices
    for (int i = 0; i < numsSize; i++) {
        if (j == 0 || nums[stack[j-1]] > nums[i]) {
            stack[j++] = i;
        }
    }

    // Traverse from the end and calculate maximum width
    for (int i = numsSize - 1; i >= 0; i--) {
        while (j > 0 && nums[stack[j-1]] <= nums[i]) {
            if (max < i - stack[j-1]) {
                max = i - stack[j-1];
            }
            j--; // Decrement `j` after processing
        }
    }

    return max;
}
