int cmpfunc(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int longestSquareStreak(int* nums, int numsSize) {
    int* mp = (int*)calloc(100001, sizeof(int));
    int res = 1;
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];
        int sqrt_num = (int)sqrt(num);
        if (sqrt_num * sqrt_num == num && mp[sqrt_num] > 0) {
            mp[num] = mp[sqrt_num] + 1;
            res = (res > mp[num]) ? res : mp[num];
        } else
            mp[num] = 1;
    }
    free(mp);
    return (res >= 2) ? res : -1;
}
