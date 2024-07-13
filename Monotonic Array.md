# Intuition
To determine if an array is monotonic, we need to check if it is either entirely non-increasing or non-decreasing. An array is non-increasing if each element is less than or equal to the previous one, and non-decreasing if each element is greater than or equal to the previous one.

# Approach
1. Initialize two boolean variables, `increasing` and `decreasing`, to `true`.
2. Iterate through the array from the second element to the end.
3. For each element, update the `increasing` variable to `false` if the current element is smaller than the previous one.
4. Similarly, update the `decreasing` variable to `false` if the current element is greater than the previous one.
5. After iterating through the array, if either `increasing` or `decreasing` is still `true`, the array is monotonic.

# Complexity
- **Time complexity:** \(O(n)\), where \(n\) is the number of elements in the array. This is because we need to iterate through the array once.
- **Space complexity:** \(O(1)\), as we are using a constant amount of space regardless of the input size.

# Code
```
bool isMonotonic(int* nums, int numsSize) 
{
    if (numsSize <= 1) 
    {
        return true;
    }
    bool increasing = true;
    bool decreasing = true;

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > nums[i-1]) {
            decreasing = false;
        }
        if (nums[i] < nums[i-1]) {
            increasing = false;
        }
    }

    return increasing || decreasing;
}
```