int minSwaps(char* s) {
    int balance = 0, swaps = 0, imbalance = 0, n = strlen(s), i;
    for (i = 0; i < n; i++) {
        if (s[i] == '[') {
            balance++;
        } else {
            balance--;
        }
        if (balance < 0) {
            imbalance++;
            balance = 0;
        }
    }
    swaps = (imbalance + 1) / 2;
    return swaps;
}
