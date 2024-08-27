# Intuition
To solve this problem, the idea is to find the maximum probability path between two nodes in a graph. This is similar to finding the shortest path, but instead of minimizing the path cost, we maximize the probability. The key is to iteratively update the probability of reaching each node based on the current known probabilities.

# Approach
1. **Initialization**: Start with an array `maxProb` to keep track of the maximum probability of reaching each node from the start node. Initialize the probability of the start node as 1.0 since the probability of starting at the start node is certain.
  
2. **Relaxation**: Iterate over all edges repeatedly, updating the probability of reaching each node through its neighbors. If going through a neighboring node offers a higher probability, update the probability of the current node.

3. **Early Termination**: If no probability is updated during an iteration, terminate early as further iterations won't change the results.

4. **Result**: The maximum probability of reaching the end node is stored in `maxProb[end_node]`.

# Complexity
- **Time complexity**: 
  The time complexity is \(O(V \times E)\), where \(V\) is the number of vertices (nodes) and \(E\) is the number of edges. This is because, in the worst case, we might relax every edge for every node.

- **Space complexity**: 
  The space complexity is \(O(V)\) due to the storage of the `maxProb` array.

# Code
```c
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
/*	Author   : Pankaj Mondal
	Date     : Tuseday, August 27, 2024, 12:54 PM
	LinkedIn : https://www.linkedin.com/in/buroush
	GitHub   : https://github.com/Buroush
	LeetCode : https://leetcode.com/Buroush        		*/
```
