## Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
A star graph is a graph where one central node is connected to all other nodes. To find the center of this graph, we need to identify the node that appears in multiple edges. Since the center node is connected to every other node, it will be present in the first two edges of the edges list.

## Approach
<!-- Describe your approach to solving the problem. -->
1. Look at the first two edges in the `edges` array.
2. Check if the first node of the first edge is equal to either node of the second edge.
   - If it is, then this node is the center.
   - Otherwise, the second node of the first edge is the center.

## Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
  $$O(1)$$ - We only look at the first two edges to determine the center.

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
  $$O(1)$$ - No additional space is used other than a few variables for comparisons.

## Code
```
int findCenter(int** edges, int edgesSize, int* edgesColSize) {
    if(edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]) {
        return edges[0][0];
    } else {
        return edges[0][1];
    }
}
```