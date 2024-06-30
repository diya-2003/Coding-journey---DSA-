# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
The problem requires us to find the maximum number of edges that can be removed while ensuring that both Alice and Bob can traverse the entire graph. This can be effectively approached using a Union-Find data structure to manage the connectivity of the nodes. By ensuring that both Alice's and Bob's graphs are fully connected using a minimum number of edges, we can determine the maximum removable edges.

# Approach
<!-- Describe your approach to solving the problem. -->
1. **Initialize Union-Find Structures**: Create two Union-Find structures, one for Alice and one for Bob, to keep track of their respective graph components.
2. **Process Type 3 Edges**: First, process edges that are common to both Alice and Bob (type 3). These edges will be added to both Union-Find structures if they help connect new components.
3. **Process Type 1 and Type 2 Edges**: Next, process edges specific to Alice (type 1) and Bob (type 2) separately. These edges will be added to the respective Union-Find structures if they help connect new components.
4. **Check Connectivity**: After processing all edges, check if both Alice's and Bob's graphs are fully connected. If they are, the result is the total number of edges minus the number of edges used to ensure connectivity.
5. **Memory Management**: Free any dynamically allocated memory before returning the result.

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
The time complexity is \(O(E \cdot \alpha(N))\), where \(E\) is the number of edges and \( \alpha \) is the inverse Ackermann function, which is very slow-growing and can be considered nearly constant.

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
The space complexity is \(O(N)\), where \(N\) is the number of nodes, due to the storage required for the Union-Find structures.

# Code
```c
#include <stdio.h>
#include <stdlib.h>
```
```c
typedef struct UnionFind {
    int *representative;
    int *component_size;
    int components;
} UnionFind;

int find_representative(UnionFind *uf, int x) {
    if (uf->representative[x] == x) {
        return x;
    }
    uf->representative[x] = find_representative(uf, uf->representative[x]);
    return uf->representative[x];
}

int perform_union(UnionFind *uf, int x, int y) {
    int x_root = find_representative(uf, x);
    int y_root = find_representative(uf, y);
    
    if (x_root == y_root) {
        return 0;
    }
    
    if (uf->component_size[x_root] > uf->component_size[y_root]) {
        uf->component_size[x_root] += uf->component_size[y_root];
        uf->representative[y_root] = x_root;
    } else {
        uf->component_size[y_root] += uf->component_size[x_root];
        uf->representative[x_root] = y_root;
    }
    
    uf->components--;
    return 1;
}

int is_connected(UnionFind *uf) {
    return uf->components == 1;
}

int maxNumEdgesToRemove(int n, int** edges, int edgesSize, int* edgesColSize) {
    UnionFind alice = {
        .representative = calloc(n + 1, sizeof(int)),
        .component_size = calloc(n + 1, sizeof(int)),
        .components = n
    };
    
    UnionFind bob = {
        .representative = calloc(n + 1, sizeof(int)),
        .component_size = calloc(n + 1, sizeof(int)),
        .components = n
    };
    
    for (int i = 0; i <= n; i++) {
        alice.representative[i] = i;
        alice.component_size[i] = 1;
        bob.representative[i] = i;
        bob.component_size[i] = 1;
    }
    
    int edges_required = 0;
    
    for (int i = 0; i < edgesSize; i++) {
        if (edges[i][0] == 3) {
            edges_required += (perform_union(&alice, edges[i][1], edges[i][2]) | perform_union(&bob, edges[i][1], edges[i][2]));
        }
    }
    
    for (int i = 0; i < edgesSize; i++) {
        if (edges[i][0] == 2) {
            edges_required += perform_union(&bob, edges[i][1], edges[i][2]);
        } else if (edges[i][0] == 1) {
            edges_required += perform_union(&alice, edges[i][1], edges[i][2]);
        }
    }
    
    if (is_connected(&alice) && is_connected(&bob)) {
        free(alice.representative);
        free(alice.component_size);
        free(bob.representative);
        free(bob.component_size);
        return edgesSize - edges_required;
    }
    
    free(alice.representative);
    free(alice.component_size);
    free(bob.representative);
    free(bob.component_size);
    return -1;
}
/*	Author : Diya Maity
	Date: Sunday, Jun 30, 2024, 2:49 PM
	LinkedIn : https://www.linkedin.com/in/diyamity
	GitHub   : https://github.com/diya-2003
	LeetCode : https://leetcode.com/u/diyamaity        		*/
```

---


```c
int main() {
    int n = 4; // Example number of nodes
    int edgesSize = 4; // Example number of edges
    int edgesColSize[4] = {3, 3, 3, 3}; // Each edge has 3 columns
    
    int edgesArray[4][3] = {
        {3, 1, 2},
        {3, 2, 3},
        {1, 3, 4},
        {2, 3, 4}
    };

    // Convert edgesArray to int**
    int** edges = malloc(edgesSize * sizeof(int*));
    for (int i = 0; i < edgesSize; i++) {
        edges[i] = malloc(3 * sizeof(int));
        for (int j = 0; j < 3; j++) {
            edges[i][j] = edgesArray[i][j];
        }
    }

    int result = maxNumEdgesToRemove(n, edges, edgesSize, edgesColSize);
    printf("Maximum number of edges that can be removed: %d\n", result);

    for (int i = 0; i < edgesSize; i++) {
        free(edges[i]);
    }
    free(edges);

    return 0;
}
/*	Author : Diya Maity
	Date: Sunday, Jun 30, 2024, 2:49 PM
	LinkedIn : https://www.linkedin.com/in/diyamity
	GitHub   : https://github.com/diya-2003
	LeetCode : https://leetcode.com/u/diyamaity        		*/

```

---

Author : Diya Maity 
Date: Sunday, Jun 30, 2024, 2:49 PM
 [LinkedIn | ](https://www.linkedin.com/in/diyamity)[GitHub | ](https://github.com/diya-2003)[LeetCode](https://leetcode.com/u/diyamaity)
