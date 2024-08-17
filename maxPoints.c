long long maxPoints(int** points, int pointsSize, int* pointsColSize) {
    int m = pointsSize;
    int n = pointsColSize[0];
    long long* dp = (long long*)malloc(n * sizeof(long long));
    
    // Initialize dp with the first row points
    for (int j = 0; j < n; j++) {
        dp[j] = points[0][j];
    }
    
    // Iterate over rows starting from the second row
    for (int i = 1; i < m; i++) {
        long long* new_dp = (long long*)malloc(n * sizeof(long long));
        long long left_max = LLONG_MIN + 1;  // Update to LLONG_MIN + 1 to avoid overflow
        
        // Left-to-Right pass
        for (int j = 0; j < n; j++) {
            left_max = fmax(left_max - 1, dp[j]);
            new_dp[j] = left_max + points[i][j];
        }
        
        long long right_max = LLONG_MIN + 1;  // Update to LLONG_MIN + 1 to avoid overflow
        
        // Right-to-Left pass
        for (int j = n - 1; j >= 0; j--) {
            right_max = fmax(right_max - 1, dp[j]);
            new_dp[j] = fmax(new_dp[j], right_max + points[i][j]);
        }
        
        // Update dp with new_dp values
        free(dp);
        dp = new_dp;
    }
    
    // Get the maximum value in the last row
    long long result = LLONG_MIN;
    for (int j = 0; j < n; j++) {
        result = fmax(result, dp[j]);
    }
    
    // Clean up and return the result
    free(dp);
    return result;
}
