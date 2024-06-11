### Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
The problem requires sorting an array `arr1` such that the relative order of elements follows another array `arr2`. Elements in `arr1` that are not in `arr2` should be placed at the end of the sorted array in ascending order. A counting sort approach seems appropriate since it allows efficient handling of the relative ordering and the placement of remaining elements.

### Approach
<!-- Describe your approach to solving the problem. -->
1. **Counting Elements**:
    - Create a count array to store the frequency of each element in `arr1`.
2. **Placing Elements by `arr2`**:
    - Iterate over `arr2` and place elements in the result array based on their counts in the count array, ensuring they follow the order in `arr2`.
3. **Placing Remaining Elements**:
    - Iterate over the count array and place any remaining elements in ascending order in the result array.
4. **Dynamic Memory Allocation**:
    - Use dynamic memory allocation for the count array and result array to handle varying input sizes.

### Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
  The time complexity is \(O(n + m + k)\), where \(n\) is the size of `arr1`, \(m\) is the size of `arr2`, and \(k\) is the maximum element value in `arr1`.
  - Finding the maximum element in `arr1` takes \(O(n)\).
  - Counting the frequency of elements in `arr1` takes \(O(n)\).
  - Placing elements based on `arr2` takes \(O(m)\).
  - Placing remaining elements takes \(O(k)\).

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
  The space complexity is \(O(n + k)\), where \(n\) is the size of `arr1` and \(k\) is the maximum element value in `arr1`.
  - The count array requires \(O(k)\) space.
  - The result array requires \(O(n)\) space.

# Code
```
#include <stdio.h>
#include <stdlib.h>

// Helper function to find the maximum element in an array
int findMax(int* arr, int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to sort the array relatively based on another array
int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize) {
    int maxElement = findMax(arr1, arr1Size);
    int* count = (int*)calloc(maxElement + 1, sizeof(int));

    // Count the frequency of each element in arr1
    for (int i = 0; i < arr1Size; i++) {
        count[arr1[i]]++;
    }

    int* ans = (int*)malloc(arr1Size * sizeof(int));
    int index = 0;

    // Place elements of arr2 in ans in the order they appear in arr2
    for (int i = 0; i < arr2Size; i++) {
        while (count[arr2[i]] > 0) {
            ans[index++] = arr2[i];
            count[arr2[i]]--;
        }
    }

    // Place remaining elements in ascending order
    for (int i = 0; i <= maxElement; i++) {
        while (count[i] > 0) {
            ans[index++] = i;
            count[i]--;
        }
    }

    free(count);
    *returnSize = arr1Size;
    return ans;
}

// Function to print the array
void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}