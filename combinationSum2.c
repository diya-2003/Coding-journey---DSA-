#include <stdlib.h>

// Helper function to compare integers for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Helper function to perform backtracking
void backtrack(int* candidates, int candidatesSize, int target, int start, int* path, int pathSize, int** result, int* returnSize, int** returnColumnSizes) {
    if (target == 0) {
        // Allocate memory for a new combination and store it
        result[*returnSize] = (int*)malloc(sizeof(int) * pathSize);
        for (int i = 0; i < pathSize; i++) {
            result[*returnSize][i] = path[i];
        }
        (*returnColumnSizes)[*returnSize] = pathSize;
        (*returnSize)++;
        return;
    }

    for (int i = start; i < candidatesSize; i++) {
        if (i > start && candidates[i] == candidates[i - 1]) {
            continue; // Skip duplicates
        }
        if (candidates[i] > target) {
            break; // No need to continue if the current candidate is greater than the remaining target
        }

        // Include the current candidate and move to the next
        path[pathSize] = candidates[i];
        backtrack(candidates, candidatesSize, target - candidates[i], i + 1, path, pathSize + 1, result, returnSize, returnColumnSizes);
    }
}

int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    // Sort candidates array to handle duplicates easily
    qsort(candidates, candidatesSize, sizeof(int), compare);

    // Initialize result array and other variables
    int** result = (int**)malloc(sizeof(int*) * 500); // Estimate a large enough space
    *returnColumnSizes = (int*)malloc(sizeof(int) * 500);
    *returnSize = 0;

    int* path = (int*)malloc(sizeof(int) * candidatesSize); // To store current combination

    // Start backtracking
    backtrack(candidates, candidatesSize, target, 0, path, 0, result, returnSize, returnColumnSizes);

    // Free temporary path memory
    free(path);

    return result;
}
