int countSquares(int** matrix, int matrixSize, int* matrixColSize) {
    int m = matrixSize, n = matrixColSize[0], dp[m][n], count = 0, i, j;
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            if (matrix[i][j] == 1) {
                if (i == 0 || j == 0)
                    dp[i][j] = 1;
                else 
                    dp[i][j] = 1 + fmin(dp[i-1][j], fmin(dp[i][j-1], dp[i-1][j-1]));
                count += dp[i][j];
            } else 
                dp[i][j] = 0;
    return count;
}
