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
