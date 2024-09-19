int compute(int a, int b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    return 0;
}
void addResult(int** results, int* size, int* capacity, int value) {
    if (*size == *capacity) {
        *capacity *= 2;
        *results = realloc(*results, *capacity * sizeof(int));
        if (*results == NULL) {
            perror("Realloc failed");
            exit(1);
        }
    }
    (*results)[(*size)++] = value;
}
int* diffWaysToCompute(char* expression, int* returnSize) {
    int n = strlen(expression);
    int capacity = 10;
    int* results = (int*)malloc(capacity * sizeof(int)); 
    *returnSize = 0;
    int isNumber = 1;
    for (int i = 0; i < n; i++) {
        if (!isdigit(expression[i])) {
            isNumber = 0;
            break;
        }
    }
    if (isNumber) {
        int num = atoi(expression);
        addResult(&results, returnSize, &capacity, num);
        return results;
    }
    for (int i = 0; i < n; i++) {
        char c = expression[i];
        if (c == '+' || c == '-' || c == '*') {
            char leftExpr[i + 1];
            strncpy(leftExpr, expression, i);
            leftExpr[i] = '\0';
            char rightExpr[n - i];
            strcpy(rightExpr, expression + i + 1);
            int leftSize = 0, rightSize = 0;
            int* leftResults = diffWaysToCompute(leftExpr, &leftSize);
            int* rightResults = diffWaysToCompute(rightExpr, &rightSize);
            for (int j = 0; j < leftSize; j++) {
                for (int k = 0; k < rightSize; k++) {
                    int result = compute(leftResults[j], rightResults[k], c);
                    addResult(&results, returnSize, &capacity, result);
                }
            }
            free(leftResults);
            free(rightResults);
        }
    }
    return results;
}
