## Intuition

The problem can be solved by minimizing the total distance that students need to move to occupy the seats. The optimal strategy involves sorting both the `seats` and `students` arrays and then pairing each student with the closest available seat.

## Approach

1. **Sort the Arrays**: 
   - Sort the `seats` array.
   - Sort the `students` array.
   
2. **Calculate the Sum of Absolute Differences**:
   - For each index `i`, calculate the absolute difference between `seats[i]` and `students[i]`.
   - Sum these absolute differences.

This approach ensures that each student is moved to the closest possible seat in an ordered manner, minimizing the total distance.

## Complexity

- **Time Complexity**: 
  - Sorting each array takes \(O(n \log n)\) where \(n\) is the number of elements (seats or students).
  - Calculating the sum of absolute differences takes \(O(n)\).
  - Thus, the overall time complexity is \(O(n \log n)\).

- **Space Complexity**:
  - The space complexity is \(O(1)\) if sorting in place, otherwise \(O(n)\) if using extra space for sorting.

## Code

```c
#include <stdlib.h>

void merge(int *arr, int left, int mid, int right) {
    int i = left, j = mid + 1;
    int k = 0;
    int *temp = (int*)malloc((right - left + 1) * sizeof(int));
    
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
    
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    
    while (j <= right) {
        temp[k++] = arr[j++];
    }
    
    for (i = left, k = 0; i <= right; i++, k++) {
        arr[i] = temp[k];
    }
    
    free(temp);
}

void mergeSort(int *arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int minMovesToSeat(int* seats, int seatsSize, int* students, int studentsSize) {
    mergeSort(seats, 0, seatsSize - 1);
    mergeSort(students, 0, studentsSize - 1);
    
    int sum = 0;
    for (int i = 0; i < seatsSize; i++) {
        sum += abs(seats[i] - students[i]);
    }
    
    return sum;
}
```