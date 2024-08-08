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
