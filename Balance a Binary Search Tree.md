### Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
The goal is to balance an unbalanced Binary Search Tree (BST). A balanced BST ensures that the depth of the two subtrees of every node never differs by more than one. To achieve this, we can perform an in-order traversal of the BST to get the nodes in a sorted array. Then, we can construct a balanced BST from this sorted array.

### Approach
<!-- Describe your approach to solving the problem. -->
1. **In-order Traversal:** Perform an in-order traversal of the given BST and store the elements in a sorted array. This is because an in-order traversal of a BST gives nodes in non-decreasing order.
2. **Construct Balanced BST:** Use the sorted array to construct a balanced BST. The middle element of the sorted array will be the root of the balanced BST. Recursively apply this to the left and right subarrays to construct the left and right subtrees.

### Complexity
- **Time Complexity:** 
  - In-order traversal: $$O(n)$$
  - Constructing the balanced BST: $$O(n)$$
  - Overall time complexity: $$O(n)$$

- **Space Complexity:** 
  - Storing the elements in an array: $$O(n)$$
  - Recursive call stack for constructing the BST: $$O(\log n)$$ (in the best case of a balanced tree), but can go up to $$O(n)$$ in the worst case of a highly unbalanced tree.
  - Overall space complexity: $$O(n)$$

### Code
``` /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int arr[10000],n;
void inorder(struct TreeNode* root)
{
    if (!root) return;
    inorder(root->left);
    arr[n++] = root->val;
    inorder(root->right);
}
struct TreeNode* BST(int l,int r)
{
    if (l > r) return NULL;
    int m = (l + r) / 2;
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = arr[m];
    node->left = BST(l, m - 1);
    node->right = BST(m + 1, r);
    return node;
}
struct TreeNode* balanceBST(struct TreeNode* root) 
{
    n = 0;
    inorder(root);
    return BST(0, n - 1);
}
```