#define MAX_LEN 1000
bool isUnique(char *s, int start, int end, int uniqueSubstrings[][2], int uniqueCount) {
    for (int i = 0; i < uniqueCount; i++) {
        int len = uniqueSubstrings[i][1] - uniqueSubstrings[i][0] + 1;
        if (len == (end - start + 1) && strncmp(s + start, s + uniqueSubstrings[i][0], len) == 0)
            return false;
    }
    return true;
}
void backtrack(char *s, int index, int uniqueSubstrings[][2], int uniqueCount, int *maxCount, int n) {
    if (index == n) {
        if (uniqueCount > *maxCount) {
            *maxCount = uniqueCount;
        }
        return;
    }
    for (int i = index; i < n; i++) {
        if (isUnique(s, index, i, uniqueSubstrings, uniqueCount)) {
            uniqueSubstrings[uniqueCount][0] = index;
            uniqueSubstrings[uniqueCount][1] = i;
            backtrack(s, i + 1, uniqueSubstrings, uniqueCount + 1, maxCount, n);
        }
    }
}
int maxUniqueSplit(char *s) {
    int n = strlen(s);
    int uniqueSubstrings[MAX_LEN][2];
    int maxCount = 0;
    backtrack(s, 0, uniqueSubstrings, 0, &maxCount, n);
    return maxCount;
}
