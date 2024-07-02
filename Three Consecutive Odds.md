# Intuition
The problem is to check if there are three consecutive odd numbers in an array. My first thought is to iterate through the array and keep a count of consecutive odd numbers. If the count reaches three at any point, we return `true`. If we complete the iteration without the count reaching three, we return `false`.

# Approach
1. Initialize a counter to zero.
2. Iterate through each element in the array.
3. For each element:
   - If it is odd, increment the counter.
   - If it is even, reset the counter to zero.
4. If the counter reaches three at any point, return `true`.
5. If the loop completes without the counter reaching three, return `false`.

# Complexity
- Time complexity: \(O(n)\), where \(n\) is the number of elements in the array. We need to iterate through the entire array once.
- Space complexity: \(O(1)\). We only use a constant amount of extra space for the counter.

# Code
```
bool threeConsecutiveOdds(int* arr, int arrSize)
{
    int count = 0;
    for (int i = 0; i < arrSize; i++) 
    {
        if (arr[i] % 2 != 0) 
        {
            count++;
            if (count == 3) 
            {
                return true;
            }
        } 
        else 
        {
            count = 0;
        }
    }
    return false;
}
```
