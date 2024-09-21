
int* lexicalOrder(int n, int* returnSize) {
    *returnSize = n;
    int* res = (int*)malloc(n * sizeof(int));
    
    int curr = 1;
    for (int i = 0; i < n; i++) {
        res[i] = curr;
        if (curr * 10 <= n) {
            curr *= 10;
        } else {
            if (curr >= n) {
                curr /= 10;
            }
            curr += 1;
            while (curr % 10 == 0) {
                curr /= 10;
            }
        }
    }
    
    return res;
}

