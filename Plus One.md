# Intuition
The problem requires adding one to a non-negative integer represented as an array of digits. If the last digit is less than 9, we simply add one to it. If it's 9, it becomes 0, and we continue this process until we find a digit less than 9 or until we reach the most significant digit. If the most significant digit is also 9, then we need to create a new array with one additional digit, with the first element being 1 and the rest being zeros.

# Approach
1. Start iterating from the least significant digit to the most significant digit.
2. If the current digit is less than 9, add one to it and return the array.
3. If the current digit is 9, set it to 0 and continue to the next iteration.
4. If we reach the most significant digit and it is 9, create a new array with one additional digit, set the most significant digit to 1, and the rest to 0.

# Complexity
- Time complexity: \( O(n) \), where \( n \) is the number of digits in the input array.
- Space complexity: \( O(n) \) or \( O(n+1) \) depending on whether a new array needs to be created.

# Code
```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) 
{
      for (int i = digitsSize - 1; i >= 0; i--) 
    {
       if (digits[i] < 9)
       {
            digits[i]++;
            *returnSize = digitsSize;
            return digits;
        }
        else
        {
            digits[i]=0;
        }
    }
        int *result=(int*)malloc((digitsSize+1) * sizeof(int));
        result[0] = 1;
        for (int i = 1; i <= digitsSize; i++) 
        {
            result[i] = 0;
        }
        digitsSize++;
    *returnSize = digitsSize;
    return result;
}
```