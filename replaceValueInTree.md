# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
The problem asks to replace the value of each node with the sum of all its cousins' values. Cousins are nodes that share the same depth but have different parents. The idea is to perform a level-order traversal (BFS or DFS) to access all nodes at the same depth, compute the total sum of nodes at each level, and adjust the node values accordingly. 

Each node's new value will be the sum of its cousins, which is the total sum of the nodes at its level minus the sum of its siblings' values.

# Approach
<!-- Describe your approach to solving the problem. -->
1. **Level-Order Traversal**: We traverse the tree level by level using DFS. At each level, we first compute the sum of all nodes' children (both left and right).
  
2. **Cousin Sum Calculation**: For each node at the current level, we subtract its direct children's sum from the total sum to calculate the sum of its cousins. We update the children's values with this cousin sum.

3. **Recursive DFS**: We repeat the above process recursively for each level until all nodes are processed.

### Steps:
- Traverse each level and calculate the sum of the node's children.
- For each node at the current level, update its children's values with the sum of cousins.
- Recursively repeat for the next level.

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
The time complexity is \( O(n) \), where \( n \) is the number of nodes in the tree, as we visit each node exactly once.

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
The space complexity is \( O(n) \), which includes the space required for the recursion stack and the array used to store nodes at each level during the traversal.

# Code

```c
void dfs(struct TreeNode **arr, int size) {
    if (size == 0) return;
    int sum = 0;
    for (int i = 0; i < size; i++) {
        struct TreeNode *node = arr[i];
        if (!node) continue;
        if (node->left) sum += node->left->val;
        if (node->right) sum += node->right->val;
    }
    struct TreeNode **childArr = malloc(size * 2 * sizeof(struct TreeNode *));
    int index = 0;
    for (int i = 0; i < size; i++) {
        struct TreeNode *node = arr[i];
        int curSum = 0;
        if (node->left) curSum += node->left->val;
        if (node->right) curSum += node->right->val;
        if (node->left) {
            node->left->val = sum - curSum;
            childArr[index++] = node->left;
        }
        if (node->right) {
            node->right->val = sum - curSum;
            childArr[index++] = node->right;
        }
    }
    dfs(childArr, index);
    free(childArr);
}

struct TreeNode* replaceValueInTree(struct TreeNode *root) {
    root->val = 0;
    struct TreeNode *arr[] = {root};
    dfs(arr, 1);
    return root;
}
```

### How the Code Works:
- **dfs**: This recursive function processes each level of the tree. It calculates the total sum of children's values at a given level and updates the children's values to reflect the sum of their cousins.
  
- **replaceValueInTree**: Initializes the process by setting the root's value to `0` (since the root has no cousins) and calls the `dfs` function.

> Before one's own interest, seeing the interest of society and country is the religion of a true citizen with a conscience. ~ Ishwar Chandra Vidyasagar
