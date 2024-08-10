To solve the problem of counting the number of regions formed by slashes (`/` and `\`) in an `n x n` grid, we can represent each `1 x 1` square in the grid as 4 smaller triangles. Each square has:

- Top-left triangle (0)
- Top-right triangle (1)
- Bottom-left triangle (2)
- Bottom-right triangle (3)

Based on the character in the square:
- A `/` divides the square into two regions, affecting triangles 0 and 3, and triangles 1 and 2.
- A `\` divides the square into two regions, affecting triangles 0 and 1, and triangles 2 and 3.
- A blank space does not divide the square, so all four triangles are part of the same region.

We can then use a Union-Find (Disjoint Set) data structure to track the connected regions across the grid. Here’s how the implementation would look:

```c
#include <stdlib.h>
#include <string.h>

int find(int* parent, int i) {
    if (parent[i] != i) {
        parent[i] = find(parent, parent[i]);
    }
    return parent[i];
}

void unionSet(int* parent, int* rank, int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);

    if (rootX != rootY) {
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

int regionsBySlashes(char** grid, int gridSize) {
    int n = gridSize;
    int totalCells = n * n * 4;
    int* parent = (int*)malloc(totalCells * sizeof(int));
    int* rank = (int*)calloc(totalCells, sizeof(int));

    for (int i = 0; i < totalCells; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int index = (i * n + j) * 4;
            char c = grid[i][j];

            // Connect triangles within the same cell
            if (c == '/') {
                unionSet(parent, rank, index + 0, index + 3);
                unionSet(parent, rank, index + 1, index + 2);
            } else if (c == '\\') {
                unionSet(parent, rank, index + 0, index + 1);
                unionSet(parent, rank, index + 2, index + 3);
            } else {
                unionSet(parent, rank, index + 0, index + 1);
                unionSet(parent, rank, index + 1, index + 2);
                unionSet(parent, rank, index + 2, index + 3);
            }

            // Connect triangles to the neighboring cells
            if (i > 0) {
                unionSet(parent, rank, index + 0, ((i - 1) * n + j) * 4 + 2);
            }
            if (j > 0) {
                unionSet(parent, rank, index + 3, (i * n + (j - 1)) * 4 + 1);
            }
        }
    }

    // Count distinct regions
    int regions = 0;
    for (int i = 0; i < totalCells; i++) {
        if (parent[i] == i) {
            regions++;
        }
    }

    free(parent);
    free(rank);
    return regions;
}
```

### Explanation:
1. **Union-Find Setup**: 
   - We represent each square with 4 triangles.
   - We initialize a parent array where each triangle is its own parent initially, and a rank array to optimize union operations.

2. **Union Operations**: 
   - Depending on whether the square contains a `/`, `\`, or blank space, we unite triangles within the square.
   - We also unite triangles that should be connected across adjacent squares.

3. **Counting Regions**: 
   - After processing the grid, the number of distinct regions corresponds to the number of unique parents in the Union-Find structure.

This approach efficiently calculates the number of regions formed by the slashes in the grid.
