void reverse(char* str, char* revStr) {
    int n = strlen(str);
    for (int i = 0; i < n; ++i) {
        revStr[i] = str[n - i - 1];
    }
    revStr[n] = '\0';
}
int kmp(const char* txt, const char* patt) {
    int pattLen = strlen(patt);
    int txtLen = strlen(txt);
    int newLen = pattLen + txtLen + 1;
    char* newString = (char*)malloc(newLen + 1);
    sprintf(newString, "%s#%s", patt, txt);
    int* pi = (int*)malloc(newLen * sizeof(int));
    memset(pi, 0, newLen * sizeof(int));

    int i = 1, k = 0;
    while (i < newLen) {
        if (newString[i] == newString[k]) {
            k++;
            pi[i] = k;
            i++;
        } else {
            if (k > 0) {
                k = pi[k - 1];
            } else {
                pi[i] = 0;
                i++;
            }
        }
    }
    int result = pi[newLen - 1];
    free(pi);
    free(newString);

    return result;
}
char* shortestPalindrome(char* s) {
    int n = strlen(s);
    if (n == 0) {
        return strdup("");
    }
    char* revStr = (char*)malloc(n + 1);
    reverse(s, revStr);
    int count = kmp(revStr, s);
    int totalLength = n + (n - count);
    char* result = (char*)malloc(totalLength + 1);
    strncpy(result, revStr, n - count);
    strcpy(result + (n - count), s);
    free(revStr);
    return result;
}
