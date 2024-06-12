To solve the problem of sorting an array containing only 0s, 1s, and 2s in-place, we can use the Dutch National Flag algorithm. This algorithm is efficient with a linear time complexity and a constant space complexity.

# Intuition
The problem can be seen as arranging three different colors (0s, 1s, and 2s) such that all 0s come first, followed by all 1s, and then all 2s. Using a three-pointer approach allows us to efficiently partition the array into three parts.

# Approach
1. **Initialize three pointers**: 
   - `start` to point to the beginning of the array.
   - `mid` to traverse the array.
   - `end` to point to the end of the array.

2. **Traverse the array with the `mid` pointer**:
   - If `nums[mid]` is 0, swap it with `nums[start]` and move both `start` and `mid` pointers to the right.
   - If `nums[mid]` is 1, just move the `mid` pointer to the right.
   - If `nums[mid]` is 2, swap it with `nums[end]` and move the `end` pointer to the left.

3. **Continue this process** until the `mid` pointer crosses the `end` pointer.

# Complexity
- **Time complexity**: \(O(n)\), where \(n\) is the number of elements in the array. Each element is processed at most once.
- **Space complexity**: \(O(1)\), as we are using only a constant amount of extra space for the pointers.

# Code
Here is the implementation of the solution:

```python
from typing import List

class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        start, mid, end = 0, 0, len(nums) - 1
    
        while mid <= end:
            if nums[mid] == 0:
                nums[start], nums[mid] = nums[mid], nums[start]
                start += 1
                mid += 1
            elif nums[mid] == 1:
                mid += 1
            else: # nums[mid] == 2
                nums[mid], nums[end] = nums[end], nums[mid]
                end -= 1
```

This code effectively sorts the array in a single pass, ensuring all 0s are at the beginning, followed by all 1s, and all 2s at the end.
