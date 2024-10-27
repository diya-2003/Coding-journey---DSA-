To solve the problem of counting square submatrices with all ones in a given \( m \times n \) matrix, we can leverage dynamic programming (DP). Here’s a step-by-step explanation and code for implementing the solution:

### Approach

1. **Initialize DP Table**: 
   - Use a 2D DP array, `dp[i][j]`, where `dp[i][j]` represents the size of the largest square submatrix with all ones that ends at position `(i, j)` in the original matrix.
   
2. **DP Transition**:
   - For each cell `(i, j)` in the matrix:
     - If `matrix[i][j] == 1`, we calculate `dp[i][j]` as the minimum of the three neighboring values to the left, above, and top-left (`dp[i-1][j]`, `dp[i][j-1]`, and `dp[i-1][j-1]`) plus one.
     - If `matrix[i][j] == 0`, `dp[i][j]` remains 0.
   
3. **Sum Up Squares**:
   - As we fill in `dp[i][j]`, we add `dp[i][j]` to a total count, since each `dp[i][j]` value represents the count of square submatrices that can be formed with `(i, j)` as the bottom-right corner.

### Complexity
- **Time Complexity**: \(O(m \times n)\), where \(m\) and \(n\) are the dimensions of the matrix.
- **Space Complexity**: \(O(m \times n)\) for the DP table, though this can be optimized to \(O(n)\) if we only keep track of the last row.

### Code (C)

```c
int countSquares(int** matrix, int matrixSize, int* matrixColSize) {
    int m = matrixSize, n = matrixColSize[0], dp[m][n], count = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (matrix[i][j] == 1) {
                if (i == 0 || j == 0)
                    dp[i][j] = 1;
                else 
                    dp[i][j] = 1 + fmin(dp[i-1][j], fmin(dp[i][j-1], dp[i-1][j-1]));
                count += dp[i][j];
            } else 
                dp[i][j] = 0;
    return count;
/*      Author   : Pankaj Mondal
        Date     : Sunday, October 27, 2024, 11:44 PM
        LinkedIn : https://www.linkedin.com/in/buroush
        GitHub   : https://github.com/Buroush
        LeetCode : https://leetcode.com/Buroush                 */

}
```

### Explanation of Code

- The code iterates through each cell in the matrix.
- For each cell with `1`, it calculates the maximum square size ending at that cell.
- Each `dp[i][j]` is added to `count` since it represents the number of square submatrices ending at `(i, j)`.

This code effectively counts all possible square submatrices with ones, achieving optimal performance.

> The welfare of the country lies in the welfare of its women. ~ Ishwar Chandra Vidyasagar
