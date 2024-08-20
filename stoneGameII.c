int stoneGameII(int* piles, int pilesSize) {
    int** dp = (int**)malloc(pilesSize * sizeof(int*));
    int i, m, x, nextM, result;
    for (i = 0; i < pilesSize; ++i) {
        dp[i] = (int*)malloc((pilesSize + 1) * sizeof(int));
        memset(dp[i], 0, (pilesSize + 1) * sizeof(int));
    }
    int* suffixSum = (int*)malloc(pilesSize * sizeof(int));
    suffixSum[pilesSize - 1] = piles[pilesSize - 1];
    for (i = pilesSize - 2; i >= 0; --i) 
        suffixSum[i] = suffixSum[i + 1] + piles[i];
    for ( i = pilesSize - 1; i >= 0; --i) {
        for ( m = 1; m <= pilesSize; ++m) {
            if (i + 2 * m >= pilesSize) {
                dp[i][m] = suffixSum[i];
            } else {
                for ( x = 1; x <= 2 * m; ++x) {
                    nextM = (x > m) ? x : m;
                    dp[i][m] = (dp[i][m] > (suffixSum[i] - dp[i + x][nextM])) ? dp[i][m] : (suffixSum[i] - dp[i + x][nextM]);                }        }    }    }
    result = dp[0][1];
    for (i = 0; i < pilesSize; ++i) 
        free(dp[i]);
    free(dp);
    free(suffixSum);
    return result;}
