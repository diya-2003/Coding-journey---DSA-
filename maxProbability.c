#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

double maxProbability(int n, int** edges, int edgesSize, int* edgesColSize, double* succProb, int succProbSize, int start_node, int end_node) {
    double* maxProb = (double*)calloc(n, sizeof(double));
    maxProb[start_node] = 1.0;

    for (int i = 0; i < n - 1; ++i) {
        bool updated = false;
        for (int j = 0; j < edgesSize; ++j) {
            int u = edges[j][0];
            int v = edges[j][1];
            double prob = succProb[j];

            if (maxProb[u] * prob > maxProb[v]) {
                maxProb[v] = maxProb[u] * prob;
                updated = true;
            }
            if (maxProb[v] * prob > maxProb[u]) {
                maxProb[u] = maxProb[v] * prob;
                updated = true;
            }
        }
        if (!updated) break;
    }

    double result = maxProb[end_node];
    free(maxProb);
    return result;
}
