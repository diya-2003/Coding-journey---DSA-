# Intuition
The problem requires finding the maximum sum of three values in a 2D board, where no two values can be in the same row or column. The intuition is to use dynamic programming to efficiently compute the maximum values for different scenarios and consider all possible orientations of the board.

# Approach
1. We use four 2D arrays to store dynamic programming results:
   - `onemax`: Maximum value from (0,0) to (r,c)
   - `rmax`: Maximum value in the current column from row 0 to r
   - `cmax`: Maximum value in the current row from column 0 to c
   - `twomax`: Maximum sum of two values that can be chosen up to (r,c)

2. We compute these arrays in a single pass over the board.

3. We then use these arrays to find the maximum sum of three values by considering the current value and the best two values that can be chosen before it (stored in `twomax`).

4. To consider all possible orientations, we flip the board horizontally and vertically and repeat the process four times.

# Complexity
- Time complexity: O(RC)
  Where R is the number of rows and C is the number of columns in the board. We perform four passes over the board, each taking O(RC) time.

- Space complexity: O(RC)
  We use four additional 2D arrays, each of size R x C.

# Code
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef long long ll;

void flip_vertical(int** board, size_t R, size_t C) {
    for (size_t r = 0; r < R / 2; r++) {
        for (size_t c = 0; c < C; c++) {
            int temp = board[r][c];
            board[r][c] = board[R - 1 - r][c];
            board[R - 1 - r][c] = temp;
        }
    }
}

void flip_horizontal(int** board, size_t R, size_t C) {
    for (size_t r = 0; r < R; r++) {
        for (size_t c = 0; c < C / 2; c++) {
            int temp = board[r][c];
            board[r][c] = board[r][C - 1 - c];
            board[r][C - 1 - c] = temp;
        }
    }
}

void fn(int** board, ll* ans, int** onemax, int** rmax, int** cmax, int** twomax, size_t R, size_t C) {
    onemax[0][0] = rmax[0][0] = cmax[0][0] = board[0][0];
    for (size_t r = 1; r < R; r++) {
        rmax[r][0] = onemax[r][0] = MAX(board[r][0], onemax[r - 1][0]);
        cmax[r][0] = board[r][0];
    }
    for (size_t c = 1; c < C; c++) {
        cmax[0][c] = onemax[0][c] = MAX(board[0][c], onemax[0][c - 1]);
        rmax[0][c] = board[0][c];
    }
    for (size_t r = 1; r < R; r++) {
        for (size_t c = 1; c < C; c++) {
            onemax[r][c] = MAX(MAX(onemax[r - 1][c], onemax[r][c - 1]), board[r][c]);
            rmax[r][c] = MAX(board[r][c], rmax[r - 1][c]);
            cmax[r][c] = MAX(board[r][c], cmax[r][c - 1]);
        }
    }
    for (size_t r = 0; r < R; r++) {
        twomax[r][0] = INT_MIN;
    }
    for (size_t c = 1; c < C; c++) {
        twomax[0][c] = INT_MIN;
    }
    for (size_t r = 1; r < R; r++) {
        for (size_t c = 1; c < C; c++) {
            int cand[4] = {
                board[r][c] + onemax[r - 1][c - 1],
                cmax[r][c - 1] + rmax[r - 1][c],
                twomax[r][c - 1],
                twomax[r - 1][c]
            };
            twomax[r][c] = MAX(MAX(cand[0], cand[1]), MAX(cand[2], cand[3]));
        }
    }
    for (size_t r = 2; r < R; r++) {
        for (size_t c = 2; c < C; c++) {
            const ll v = board[r][c];
            const int t = twomax[r - 1][c - 1];
            if (t != INT_MIN) {
                *ans = MAX(v + t, *ans);
            }
        }
    }
}

ll maximumValueSum(int** board, int boardSize, int* boardColSize) {
    const size_t R = boardSize;
    const size_t C = boardColSize[0];
    ll ans = LLONG_MIN;

    int** onemax = (int**)malloc(R * sizeof(int*));
    int** rmax = (int**)malloc(R * sizeof(int*));
    int** cmax = (int**)malloc(R * sizeof(int*));
    int** twomax = (int**)malloc(R * sizeof(int*));

    for (size_t i = 0; i < R; i++) {
        onemax[i] = (int*)malloc(C * sizeof(int));
        rmax[i] = (int*)malloc(C * sizeof(int));
        cmax[i] = (int*)malloc(C * sizeof(int));
        twomax[i] = (int*)malloc(C * sizeof(int));
    }

    fn(board, &ans, onemax, rmax, cmax, twomax, R, C);
    flip_horizontal(board, R, C);
    fn(board, &ans, onemax, rmax, cmax, twomax, R, C);
    flip_vertical(board, R, C);
    fn(board, &ans, onemax, rmax, cmax, twomax, R, C);
    flip_horizontal(board, R, C);
    fn(board, &ans, onemax, rmax, cmax, twomax, R, C);

    for (size_t i = 0; i < R; i++) {
        free(onemax[i]);
        free(rmax[i]);
        free(cmax[i]);
        free(twomax[i]);
    }
    free(onemax);
    free(rmax);
    free(cmax);
    free(twomax);

    return ans;
}
```

This approach efficiently solves the problem by using dynamic programming to avoid redundant calculations and considering all possible orientations of the board to ensure the global maximum is found.
