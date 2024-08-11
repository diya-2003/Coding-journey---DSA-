#include <stdbool.h>

// Helper function to check if the grid is connected
void dfs(int** grid, int gridSize, int gridColSize, int x, int y, bool** visited) {
    if (x < 0 || x >= gridSize || y < 0 || y >= gridColSize || grid[x][y] == 0 || visited[x][y])
        return;
    
    visited[x][y] = true;
    
    dfs(grid, gridSize, gridColSize, x + 1, y, visited);
    dfs(grid, gridSize, gridColSize, x - 1, y, visited);
    dfs(grid, gridSize, gridColSize, x, y + 1, visited);
    dfs(grid, gridSize, gridColSize, x, y - 1, visited);
}

int countIslands(int** grid, int gridSize, int gridColSize) {
    bool** visited = (bool**)malloc(gridSize * sizeof(bool*));
    for (int i = 0; i < gridSize; i++) {
        visited[i] = (bool*)malloc(gridColSize * sizeof(bool));
        memset(visited[i], 0, gridColSize * sizeof(bool));
    }
    
    int count = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize; j++) {
            if (grid[i][j] == 1 && !visited[i][j]) {
                dfs(grid, gridSize, gridColSize, i, j, visited);
                count++;
            }
        }
    }
    
    for (int i = 0; i < gridSize; i++) {
        free(visited[i]);
    }
    free(visited);
    
    return count;
}

int minDays(int** grid, int gridSize, int* gridColSize) {
    if (countIslands(grid, gridSize, *gridColSize) != 1) {
        return 0;
    }
    
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < *gridColSize; j++) {
            if (grid[i][j] == 1) {
                grid[i][j] = 0;
                if (countIslands(grid, gridSize, *gridColSize) != 1) {
                    return 1;
                }
                grid[i][j] = 1;
            }
        }
    }
    
    return 2;
}
#include <stdio.h>
#include <stdlib.h>

// Function declarations
int minDays(int** grid, int gridSize, int* gridColSize);
int countIslands(int** grid, int gridSize, int gridColSize);
void dfs(int** grid, int gridSize, int gridColSize, int x, int y, bool** visited);

// Function to print the grid (for debugging purposes)
void printGrid(int** grid, int gridSize, int gridColSize) {
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Main function with test cases
int main() {
    int gridSize, gridColSize;

    // Test Case 1
    int grid1Data[3][3] = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}
    };
    gridSize = 3;
    gridColSize = 3;
    int** grid1 = (int**)malloc(gridSize * sizeof(int*));
    for (int i = 0; i < gridSize; i++) {
        grid1[i] = (int*)malloc(gridColSize * sizeof(int));
        for (int j = 0; j < gridColSize; j++) {
            grid1[i][j] = grid1Data[i][j];
        }
    }
    printf("Test Case 1:\n");
    printGrid(grid1, gridSize, gridColSize);
    printf("Minimum days to disconnect: %d\n\n", minDays(grid1, gridSize, &gridColSize));

    // Test Case 2
    int grid2Data[3][3] = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };
    gridSize = 3;
    gridColSize = 3;
    int** grid2 = (int**)malloc(gridSize * sizeof(int*));
    for (int i = 0; i < gridSize; i++) {
        grid2[i] = (int*)malloc(gridColSize * sizeof(int));
        for (int j = 0; j < gridColSize; j++) {
            grid2[i][j] = grid2Data[i][j];
        }
    }
    printf("Test Case 2:\n");
    printGrid(grid2, gridSize, gridColSize);
    printf("Minimum days to disconnect: %d\n\n", minDays(grid2, gridSize, &gridColSize));

    // Test Case 3
    int grid3Data[3][3] = {
        {1, 0, 0},
        {0, 0, 0},
        {0, 0, 1}
    };
    gridSize = 3;
    gridColSize = 3;
    int** grid3 = (int**)malloc(gridSize * sizeof(int*));
    for (int i = 0; i < gridSize; i++) {
        grid3[i] = (int*)malloc(gridColSize * sizeof(int));
        for (int j = 0; j < gridColSize; j++) {
            grid3[i][j] = grid3Data[i][j];
        }
    }
    printf("Test Case 3:\n");
    printGrid(grid3, gridSize, gridColSize);
    printf("Minimum days to disconnect: %d\n\n", minDays(grid3, gridSize, &gridColSize));

    // Free allocated memory
    for (int i = 0; i < gridSize; i++) {
        free(grid1[i]);
        free(grid2[i]);
        free(grid3[i]);
    }
    free(grid1);
    free(grid2);
    free(grid3);

    return 0;
}
