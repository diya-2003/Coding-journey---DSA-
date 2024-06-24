# Intuition
When faced with the problem of moving all zeros to the end of an array while maintaining the relative order of the non-zero elements, one straightforward approach is to make a single pass through the array to move the non-zero elements to the front. Then, in a second pass, we can fill the remaining positions with zeros.

# Approach
1. **Two-Pointer Technique:** We'll use two pointers `i` and `j`. The pointer `i` will iterate through the array, while `j` will keep track of the position where the next non-zero element should be placed.
2. **First Pass:** As we iterate through the array with `i`, every time we encounter a non-zero element, we'll place it at the position indicated by `j` and then increment `j`.
3. **Second Pass:** After the first pass, `j` will indicate the position where the first zero should be placed. We'll iterate from `j` to the end of the array, setting each position to zero.

# Complexity
- Time complexity: 
  - The time complexity is $$O(n)$$ because we iterate through the array twice (once for the non-zero elements and once for the zeros), where `n` is the number of elements in the array.
- Space complexity: 
  - The space complexity is $$O(1)$$ because we are modifying the array in place and not using any extra space proportional to the input size.

# Code
```c
void moveZeroes(int* nums, int numsSize) {
    int i, j;
    // First pass: move non-zero elements to the front
    for (i = 0, j = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            nums[j] = nums[i];
            j++;
        }
    }
    // Second pass: fill the rest of the array with zeros
    for (; j < numsSize; nums[j++] = 0);
}
```

### Explanation:
1. **First Loop:**
   ```c
   for (i = 0, j = 0; i < numsSize; i++) {
       if (nums[i] != 0) {
           nums[j] = nums[i];
           j++;
       }
   }
   ```
   - This loop goes through each element in the array. If the element is non-zero, it is moved to the position indicated by `j`, and `j` is incremented.
   - By the end of this loop, all non-zero elements are moved to the front of the array in their original order.

2. **Second Loop:**
   ```c
   for (; j < numsSize; nums[j++] = 0);
   ```
   - This loop fills the remaining positions in the array (from `j` to `numsSize - 1`) with zeros.
   - The `nums[j++] = 0` statement sets the current position to zero and then increments `j`.