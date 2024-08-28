#include <stdbool.h>

void dfs(int** grid1, int grid1Size, int grid1ColSize, int** grid2, int grid2Size, int grid2ColSize, int row, int col, bool* isSubIsland) {
    // Check bounds and if the current cell is part of the island in grid2
    if (row < 0 || row >= grid2Size || col < 0 || col >= grid2ColSize || grid2[row][col] == 0)
        return;

    // If the corresponding cell in grid1 is 0, then grid2's island is not a sub-island
    if (grid1[row][col] == 0)
        *isSubIsland = false;

    // Mark the current cell in grid2 as visited
    grid2[row][col] = 0;

    // Explore in all 4 directions
    dfs(grid1, grid1Size, grid1ColSize, grid2, grid2Size, grid2ColSize, row + 1, col, isSubIsland);
    dfs(grid1, grid1Size, grid1ColSize, grid2, grid2Size, grid2ColSize, row - 1, col, isSubIsland);
    dfs(grid1, grid1Size, grid1ColSize, grid2, grid2Size, grid2ColSize, row, col + 1, isSubIsland);
    dfs(grid1, grid1Size, grid1ColSize, grid2, grid2Size, grid2ColSize, row, col - 1, isSubIsland);
}

int countSubIslands(int** grid1, int grid1Size, int* grid1ColSize, int** grid2, int grid2Size, int* grid2ColSize) {
    int subIslandCount = 0;

    // Traverse each cell in grid2
    for (int i = 0; i < grid2Size; i++) {
        for (int j = 0; j < grid2ColSize[i]; j++) {
            if (grid2[i][j] == 1) { // Found an island in grid2
                bool isSubIsland = true;
                dfs(grid1, grid1Size, *grid1ColSize, grid2, grid2Size, *grid2ColSize, i, j, &isSubIsland);
                if (isSubIsland) {
                    subIslandCount++;
                }
            }
        }
    }

    return subIslandCount;
}
