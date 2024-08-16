# Intuition
The problem asks for the maximum distance between any two integers taken from two different arrays, where the distance is defined as the absolute difference between the integers. Given that each array is sorted in ascending order, the maximum distance will likely involve the smallest or largest elements from these arrays.

# Approach
To solve this problem, the idea is to iterate through the arrays and keep track of the minimum and maximum elements encountered so far. For each array, compute the potential distances by comparing:
1. The current array's largest element with the global minimum.
2. The current array's smallest element with the global maximum.
Update the maximum distance based on these comparisons. This ensures that we're always considering the optimal pairs of values from different arrays.

# Complexity
- **Time complexity**: \( O(n) \)
  - We traverse each array exactly once, making the solution linear with respect to the number of arrays.
- **Space complexity**: \( O(1) \)
  - We only use a constant amount of extra space for variables like `min_val`, `max_val`, and `max_dist`.

# Code
```c
#include <limits.h>
#include <stdlib.h>

int maxDistance(int** arrays, int arraysSize, int* arraysColSize) {
    int min_val = arrays[0][0];
    int max_val = arrays[0][arraysColSize[0] - 1];
    int max_dist = 0;

    for (int i = 1; i < arraysSize; i++) {
        int current_min = arrays[i][0];
        int current_max = arrays[i][arraysColSize[i] - 1];

        int dist1 = abs(current_max - min_val);
        int dist2 = abs(max_val - current_min);

        if (dist1 > max_dist) {
            max_dist = dist1;
        }
        if (dist2 > max_dist) {
            max_dist = dist2;
        }

        if (current_min < min_val) {
            min_val = current_min;
        }
        if (current_max > max_val) {
            max_val = current_max;
        }
    }

    return max_dist;
}
```
