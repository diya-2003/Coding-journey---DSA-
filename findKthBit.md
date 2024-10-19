## Intuition
The binary string `S_n` is recursively constructed from `S_{n-1}`. It consists of three parts:
1. The original string `S_{n-1}`,
2. A single '1' in the middle,
3. The reverse and inverted version of `S_{n-1}`.

Rather than generating the entire string, we can observe that:
- If `k` is in the first half, it corresponds to the same position in `S_{n-1}`.
- If `k` is in the second half, it corresponds to a reversed and inverted position from `S_{n-1}`.
- If `k` is exactly in the middle, it is always '1'.

Thus, we can recursively determine the kth bit without actually constructing the string.

## Approach
1. **Base Case**: If `n == 1`, return '0' because `S1 = "0"`.
2. **Recursive Step**:
   - Calculate the length of the string `S_n`, which is `2^n - 1`.
   - The middle position is `mid = 2^{n-1}`.
   - If `k == mid`, return '1' (the middle element).
   - If `k < mid`, recursively find the kth bit in `S_{n-1}`.
   - If `k > mid`, find the mirror position in the first half of `S_{n-1}`, then invert the bit.

## Complexity
- **Time Complexity**: 
  - Each recursive call reduces the problem size by half, resulting in `O(n)` recursive calls. Thus, the time complexity is `O(n)`.
  
- **Space Complexity**: 
  - The space complexity is also `O(n)` due to the recursive call stack, which can go as deep as `n`.

## Code
```c
char findKthBit(int n, int k) {
    if (n == 1)
        return '0';
    int length = (1 << n) - 1, mid = length / 2 + 1;
    if (k == mid)
        return '1';
    else if (k < mid)
        return findKthBit(n - 1, k);
    else {
        int mirrorK = mid - (k - mid);
        char bit = findKthBit(n - 1, mirrorK);
        return bit == '0' ? '1' : '0';}
}
/*      Author   : Pankaj Mondal
        Date     : Saturday, October 19, 2024, 8:41 PM
        LinkedIn : https://www.linkedin.com/in/buroush
        GitHub   : https://github.com/Buroush
        LeetCode : https://leetcode.com/Buroush                 */
``` 

> "No matter how big a man becomes he should always remember his past." ~ Ishwar Chandra Vidyasagar
