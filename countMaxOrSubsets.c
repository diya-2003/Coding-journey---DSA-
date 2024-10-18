int countMaxOrSubsets(int* nums, int numsSize) {
    int i, maxOr = 0, count = 0, totalSubsets = 1 << numsSize, subset, currentOr;
    for ( i = 0; i < numsSize; i++) 
        maxOr |= nums[i];
    for ( subset = 1; subset < totalSubsets; subset++) {
        currentOr = 0;
        for ( i = 0; i < numsSize; i++) 
            if (subset & (1 << i))
                currentOr |= nums[i];
        if (currentOr == maxOr)
            count++;
    }
    return count;
}
