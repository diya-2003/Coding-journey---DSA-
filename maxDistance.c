#include <limits.h>
#include <stdlib.h>

int maxDistance(int** arrays, int arraysSize, int* arraysColSize) {
    int min_val = arrays[0][0], max_val = arrays[0][arraysColSize[0] - 1], max_dist = 0;
    for (int i = 1; i < arraysSize; i++) {
        int current_min = arrays[i][0], current_max = arrays[i][arraysColSize[i] - 1], dist1 = abs(current_max - min_val), dist2 = abs(max_val - current_min);
        if (dist1 > max_dist) {
            max_dist = dist1;        }
        if (dist2 > max_dist) {
            max_dist = dist2;        }
        if (current_min < min_val) {
            min_val = current_min;        }
        if (current_max > max_val) {
            max_val = current_max;        }    }    
    return max_dist; }
