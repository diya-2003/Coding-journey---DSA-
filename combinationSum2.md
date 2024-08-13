
# Intuition
The problem requires us to find all unique combinations of candidate numbers that sum to a given target. The key challenge is to ensure each combination is unique and that each candidate number can only be used once per combination. Sorting the candidate list helps in efficiently handling duplicates and pruning unnecessary recursion paths.

# Approach
The approach involves a backtracking algorithm combined with sorting. First, the candidate list is sorted to facilitate easy detection of duplicates. We then recursively explore potential combinations by either including or excluding each candidate, moving forward in the list, and reducing the target accordingly. If the target is reduced to zero, a valid combination is found and added to the result. To avoid duplicates, we skip over consecutive identical numbers in the sorted list.

# Complexity
- Time complexity:
  The time complexity is roughly \(O(2^n)\) where \(n\) is the number of candidates. This is because each candidate can either be included or excluded, leading to a binary decision at each step.

- Space complexity:
  The space complexity is \(O(k \times m)\), where \(k\) is the number of unique combinations found and \(m\) is the average length of these combinations. This space is used to store the results. Additionally, the recursion stack will take up \(O(n)\) space in the worst case.

# Code
```c
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
