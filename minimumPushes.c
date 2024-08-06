int compare(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}
int minimumPushes(char* word) {
    int freq[26] = {0};
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        freq[word[i] - 'a']++;
    }
    qsort(freq, 26, sizeof(int), compare);
    int sz = 0, push = 1, ans = 0;
    for (; sz < 26 && freq[sz] != 0; sz++) {
        if (sz >= 8 && sz % 8 == 0) push++;
        ans += freq[sz] * push;
    }

    return ans;
}
