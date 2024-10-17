void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;}
int maximumSwap(int num) {
    char numStr[11];
    sprintf(numStr, "%d", num);
    int n = strlen(numStr);
    int last[10];
    for (int i = 0; i < 10; i++) 
        last[i] = -1;
    for (int i = 0; i < n; i++) 
        last[numStr[i] - '0'] = i;
    for (int i = 0; i < n; i++)
        for (int d = 9; d > numStr[i] - '0'; d--)
            if (last[d] > i) {
                swap(&numStr[i], &numStr[last[d]]);
                int swappedNum;
                sscanf(numStr, "%d", &swappedNum);
                return swappedNum;
            }
    return num;
}
