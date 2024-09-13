int* xorQueries(int* arr, int arrSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    *returnSize = queriesSize;
    int* result = (int*)malloc(sizeof(int) * queriesSize);
    int* prefixXor = (int*)malloc(sizeof(int) * arrSize);
    prefixXor[0] = arr[0];
    for (int i = 1; i < arrSize; i++) {
        prefixXor[i] = prefixXor[i - 1] ^ arr[i];
    }
    for (int i = 0; i < queriesSize; i++) {
        int left = queries[i][0];
        int right = queries[i][1];
        if (left == 0) {
            result[i] = prefixXor[right];
        } else {
            result[i] = prefixXor[right] ^ prefixXor[left - 1];
        }
    }
    free(prefixXor);
    return result;
}
