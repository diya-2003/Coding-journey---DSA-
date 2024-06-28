### Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
The problem is to determine the sign of the product of an array of integers without actually computing the product, as it may lead to overflow issues.

### Approach
<!-- Describe your approach to solving the problem. -->
To determine the sign of the product of an array of integers, we can iterate through the array and:
1. Return `0` immediately if any element is `0`, because the product will be `0`.
2. Keep track of the sign of the product by flipping it whenever we encounter a negative number.

### Complexity
- **Time complexity:**  
  The time complexity is $$O(n)$$ since we are iterating through the array once.
- **Space complexity:**  
  The space complexity is $$O(1)$$ because we are using a constant amount of extra space.

### Code
```
int arraySign(int* nums, int numsSize) 
{
    int productSign=1;

    for (int i = 0; i < numsSize; i++) 
    {
        if (nums[i] == 0)
        {
            return 0;
        }
        else if (nums[i] < 0)
        {
            productSign=-productSign;
        }
    }
    return productSign;
}
```