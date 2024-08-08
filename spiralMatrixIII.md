### Approach:
1. **Initialize Direction Vectors:** 
   Define direction vectors to control movement in the grid in the order of right (east), down (south), left (west), and up (north). 
   - `right` → `(0, 1)`
   - `down` → `(1, 0)`
   - `left` → `(0, -1)`
   - `up` → `(-1, 0)`

2. **Spiral Movement Logic:** 
   Start from the initial position `(rStart, cStart)`, move in a spiral by following the direction vectors. The number of steps in each direction increases after every two movements (once for each axis).

3. **Check for Valid Positions:**
   At each step, check whether the new position is within the grid's boundaries. If it is, add it to the result array.

4. **Stopping Condition:**
   The process continues until all positions in the grid have been visited, i.e., until `rows * cols` positions are collected.

5. **Memory Allocation:**
   Allocate memory for the output array and the column sizes array, returning the results as per the function signature.

### Implementation:

```c
#include <stdlib.h>

int** spiralMatrixIII(int rows, int cols, int rStart, int cStart, int* returnSize, int** returnColumnSizes) {
    // Directions: right, down, left, up
    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int totalCells = rows * cols;
    int** result = (int**)malloc(totalCells * sizeof(int*));
    *returnColumnSizes = (int*)malloc(totalCells * sizeof(int));
    *returnSize = 0;
    
    int r = rStart, c = cStart;
    int dir = 0; // Start with direction "right"
    int steps = 1; // Number of steps in the current direction

    while (*returnSize < totalCells) {
        for (int i = 0; i < 2; i++) { // Each direction gets repeated twice
            for (int j = 0; j < steps; j++) {
                if (r >= 0 && r < rows && c >= 0 && c < cols) {
                    result[*returnSize] = (int*)malloc(2 * sizeof(int));
                    result[*returnSize][0] = r;
                    result[*returnSize][1] = c;
                    (*returnColumnSizes)[*returnSize] = 2;
                    (*returnSize)++;
                }
                r += directions[dir][0];
                c += directions[dir][1];
            }
            dir = (dir + 1) % 4; // Change direction
        }
        steps++; // Increment step size after completing two directions
    }
    
    return result;
}
```

### Explanation:
- **Direction Management:** The direction changes occur sequentially in the order of right, down, left, and up.
- **Step Control:** The step size increases every two direction changes to maintain the spiral growth.
- **Boundary Check:** Each position is checked to see if it lies within the grid bounds before being added to the result.
