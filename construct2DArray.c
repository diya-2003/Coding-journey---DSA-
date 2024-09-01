int** construct2DArray(int* original, int originalSize, int m, int n, int* returnSize, int** returnColumnSizes) {
    // Check if the number of elements in the 1D array matches the total number of elements in the 2D array
    if (originalSize != m * n) {
        *returnSize = 0;
        return NULL;
    }

    // Allocate memory for the 2D array
    int** result = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        result[i] = (int*)malloc(n * sizeof(int));
    }

    // Populate the 2D array with elements from the 1D array
    int index = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = original[index++];
        }
    }

    // Set the return values
    *returnSize = m;
    *returnColumnSizes = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        (*returnColumnSizes)[i] = n;
    }

    return result;
}
