### Intuition

To solve the problem of finding the minimum number of recolors needed to achieve at least one contiguous block of length \( k \) with only 'W' blocks, we can use a sliding window approach. The idea is to keep track of the number of 'B' blocks within the current window of size \( k \) and try to minimize this number. The goal is to find the minimum number of 'B' blocks in any window of size \( k \), as converting all 'B' blocks to 'W' will give us the desired result.

### Approach

1. **Initial Window Calculation**: Calculate the number of 'B' blocks in the initial window of size \( k \).
2. **Sliding the Window**: Move the window one block at a time from left to right. For each step:
   - Remove the effect of the block that is sliding out of the window.
   - Add the effect of the block that is sliding into the window.
   - Track the maximum number of 'B' blocks found in any window.
3. **Compute Result**: The minimum number of recolors needed is \( k - \text{max number of 'B' blocks in any window} \).

### Complexity

- **Time Complexity**: \( O(n) \)
  - We perform a constant amount of work per block as we slide the window across the string. This results in a linear time complexity where \( n \) is the length of the string.

- **Space Complexity**: \( O(1) \)
  - We are only using a few extra variables to keep track of counts and the maximum, so the space complexity is constant.

### Code
```
int minimumRecolors(char* blocks, int k) 
{
    int max=0,current=0;
    for(int i=0;i<k;i++) 
    {
        if(blocks[i]=='B') 
        {
            current++;
        }
    }
    max=current;
    for(int i=k;blocks[i]!='\0';i++) 
    {
        if(blocks[i-k]=='B') 
        {
            current--;
        }
        if (blocks[i] == 'B') 
        {
            current++;
        }
        if (current > max) 
        {
            max=current;
        }
    }
    return k-max;
}
```