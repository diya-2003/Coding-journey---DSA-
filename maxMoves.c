int maxMoves(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize, n = gridColSize[0], maxMoves = 0, dp[m][n];
    memset(dp, 0, sizeof(dp));
    for (int col = n - 2; col >= 0; col--)
        for (int row = 0; row < m; row++) {
            if (row > 0 && grid[row - 1][col + 1] > grid[row][col]) 
                dp[row][col] = dp[row][col] > (dp[row - 1][col + 1] + 1) ? dp[row][col] : (dp[row - 1][col + 1] + 1);
            if (grid[row][col + 1] > grid[row][col])
                dp[row][col] = dp[row][col] > (dp[row][col + 1] + 1) ? dp[row][col] : (dp[row][col + 1] + 1);
            if (row < m - 1 && grid[row + 1][col + 1] > grid[row][col])
                dp[row][col] = dp[row][col] > (dp[row + 1][col + 1] + 1) ? dp[row][col] : (dp[row + 1][col + 1] + 1);
        }
    for (int row = 0; row < m; row++)
        maxMoves = maxMoves > dp[row][0] ? maxMoves : dp[row][0];
    return maxMoves;
}
