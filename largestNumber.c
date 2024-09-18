int compare(const void* a, const void* b) {
    char* num1 = *(char**)a;
    char* num2 = *(char**)b;
    char order1[25], order2[25];
    strcpy(order1, num1);
    strcat(order1, num2);
    strcpy(order2, num2);
    strcat(order2, num1);
    return strcmp(order2, order1);
}
char* largestNumber(int* nums, int numsSize) {
    char** strNums = (char**)malloc(numsSize * sizeof(char*));
    for (int i = 0; i < numsSize; i++) {
        strNums[i] = (char*)malloc(12 * sizeof(char));
        sprintf(strNums[i], "%d", nums[i]);
    }
    qsort(strNums, numsSize, sizeof(char*), compare);
    if (strcmp(strNums[0], "0") == 0) {
        char* zeroResult = (char*)malloc(2 * sizeof(char));
        strcpy(zeroResult, "0");
        return zeroResult;
    }
    int totalLength = 0;
    for (int i = 0; i < numsSize; i++) {
        totalLength += strlen(strNums[i]);
    }
    char* result = (char*)malloc((totalLength + 1) * sizeof(char)); 
    result[0] = '\0';
    for (int i = 0; i < numsSize; i++) {
        strcat(result, strNums[i]);
    }
    for (int i = 0; i < numsSize; i++) {
        free(strNums[i]);
    }
    free(strNums);
    return result;
}
