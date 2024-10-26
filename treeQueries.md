### Intuition
To solve this problem, we need to calculate the height of the tree after removing specific subtrees based on each query. Since each query is independent, we can return the tree to its original state after each one. The challenge lies in efficiently computing the tree height without recalculating it from scratch for each query.

### Approach
1. **Traverse the Tree to Compute Heights**: 
   - First, we compute the height of every subtree rooted at each node. This information will help us avoid recalculating subtree heights repeatedly.
  
2. **Precompute Effective Heights**:
   - We then precompute an array (`comp`) where `comp[node_val]` represents the maximum height of the remaining tree if we remove the subtree rooted at `node_val`.
   - This is done by comparing the height from the sibling subtree and the maximum height of the parent’s subtree if it bypasses the removed node.

3. **Answer Queries Using Precomputed Values**:
   - For each query, we directly access `comp[queries[i]]` to get the height of the tree with the specified subtree removed. This makes each query retrieval `O(1)`.

### Complexity

- **Time Complexity**: \(O(n + m)\), where \(n\) is the number of nodes (for the tree traversal and height precomputation) and \(m\) is the number of queries.
- **Space Complexity**: \(O(n)\) for storing heights and effective heights in `hlist` and `comp`.

### Code

```c
void compute(struct TreeNode * curr, int * comp, int * hlist, struct TreeNode* p, int height, struct TreeNode* sibnode, int level){
    if (curr == NULL)
        return;
    if (p == NULL)
        comp[curr->val] = -1;
    else if ((comp[p->val] == height) || ((sibnode != NULL) && (hlist[sibnode->val] >= hlist[curr->val])))
        comp[curr->val] = height;               
    else{
        int v1 = ((sibnode == NULL) ? -1 : (hlist[sibnode->val])) + level;
        comp[curr->val] = comp[p->val] > v1 ? comp[p->val] : v1;}
    compute(curr->left,  comp, hlist, curr, height, curr->right, level + 1);
    compute(curr->right, comp, hlist, curr, height, curr->left, level + 1);}
int traverse(struct TreeNode * curr, int * hlist){
    if (curr == NULL)
        return -1;
    int h1 = traverse(curr->left, hlist), h2 = traverse(curr->right, hlist);
    hlist[curr->val] = ((h1 > h2) ? (h1) : (h2)) + 1;
    return hlist[curr->val];}
int* treeQueries(struct TreeNode* root, int* queries, int queriesSize, int* returnSize){
    * returnSize = 0;
    int *answer = malloc(sizeof(int) * queriesSize),*hlist  = malloc(sizeof(int) * 100001),*comp = malloc(sizeof(int) * 100001), h = traverse(root, hlist), i;
    compute(root, comp, hlist, NULL, h, NULL, 0);
    for (i = 0; i < queriesSize; i++){
        (*returnSize) ++;
        answer[i] = comp[queries[i]];}
    free(hlist);
    free(comp);
    return answer;}
/*      Author   : Pankaj Mondal
        Date     : Saturday, October 26, 2024, 4:17 PM
        LinkedIn : https://www.linkedin.com/in/buroush
        GitHub   : https://github.com/Buroush
        LeetCode : https://leetcode.com/Buroush                 */

```

### Explanation of Code

- **`traverse` Function**: Recursively calculates the height of each node’s subtree, storing it in `hlist[node_val]`.
- **`compute` Function**: Calculates effective heights for each node, storing them in `comp[node_val]` to answer queries efficiently.
- **`treeQueries` Function**: Answers each query in constant time using the precomputed `comp` array, making the solution efficient even for large input sizes.

> For wise and good men always feel disinclined to hurt those that are of much less strength than themselves ~ Ram Mohan Roy
