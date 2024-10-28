# Intuition
To find the longest "square streak" in an array, we need to identify sequences where each element is the square of the previous one. Since squares grow exponentially, our task simplifies if we first sort the array and then track streaks based on the square-root relationship of numbers.

# Approach
1. **Sort the Array**: Begin by sorting `nums` so that potential square streaks are easier to identify sequentially.
2. **Track Streaks with Array**: Use an auxiliary array `mp` to track the length of square streaks for each number. This allows quick lookup to see if the square root of a number has already started a streak.
3. **Iterate and Update Streaks**: For each element, check if it is a perfect square of a previous element in the sorted order. If it is, update the current element's streak length in `mp` as one more than its square root’s streak length. Otherwise, initialize it as a new streak.
4. **Determine Longest Streak**: Keep track of the longest streak found and return it only if it meets the minimum required length (2); otherwise, return `-1`.

# Complexity

- **Time Complexity**:  
  Sorting takes \(O(n \log n)\), where \(n\) is `numsSize`. Iterating through the array once to update streak lengths is \(O(n)\). Thus, the overall time complexity is \(O(n \log n)\).

- **Space Complexity**:  
  The auxiliary array `mp` has a fixed size of \(O(10^5)\), making the space complexity \(O(1)\) in practical terms, as it doesn't grow with input size.

# Code
```c
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
/*      Author   : Pankaj Mondal
        Date     : Monday, October 28, 2024, 8:31 PM
        LinkedIn : https://www.linkedin.com/in/buroush
        GitHub   : https://github.com/Buroush
        LeetCode : https://leetcode.com/Buroush                 */

```
