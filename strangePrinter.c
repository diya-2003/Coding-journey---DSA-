int strangePrinter(char* s) {
    int n = strlen(s), dp[n][n];
    int i, len, j, k, turns;
    // Initialize the dp table
    for (i = 0; i < n; i++) {
        dp[i][i] = 1; // Single character case
    }

    for ( len = 2; len <= n; len++) {
        for ( i = 0; i <= n - len; i++) {
            j = i + len - 1;
            dp[i][j] = dp[i + 1][j] + 1; // Initialize to one extra turn
            for (k = i; k < j; k++) {
                turns = dp[i][k] + dp[k + 1][j];
                if (s[k] == s[j]) {
                    turns--;
                }
                dp[i][j] = dp[i][j] < turns ? dp[i][j] : turns;
            }
        }
    }
    
    return dp[0][n-1];
}
