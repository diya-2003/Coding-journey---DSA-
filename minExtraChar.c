int minExtraChar(char *s, char **dictionary, int dictionarySize) {
    int min(int a, int b) {
        return a < b ? a : b;
    }
    bool isInDictionary(char *s, int start, int end, char **dictionary, int dictionarySize) {


        char temp[end - start + 2];
        strncpy(temp, s + start, end - start + 1);
        temp[end - start + 1] = '\0';
        
        for (int i = 0; i < dictionarySize; i++) {
            if (strcmp(temp, dictionary[i]) == 0) {
                return true;
            }
        }
        return false;
    }
    int n = strlen(s);
    int dp[n + 1];
    for (int i = 0; i <= n; i++) {
        dp[i] = INT_MAX;
    }
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] + 1;
        for (int j = 0; j < i; j++) {
            if (isInDictionary(s, j, i - 1, dictionary, dictionarySize)) {
                dp[i] = min(dp[i], dp[j]);
            }
        }
    }
    return dp[n];
}
