int countConsistentStrings(char *allowed, char **words, int wordsSize) {
    int ans = 0;
    bool allowedSet[26] = {false};
    for (int i = 0; allowed[i] != '\0'; i++)
        allowedSet[allowed[i] - 'a'] = true;
    for (int i = 0; i < wordsSize; i++) {
        bool flag = true;
        for (int j = 0; words[i][j] != '\0'; j++) {
            char ch = words[i][j];
            if (!allowedSet[ch - 'a']) {
                flag = false;
                break;
            }}
        ans += flag;
}
    return ans;
}
