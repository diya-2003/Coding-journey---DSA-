# Intuition
The postorder traversal of a binary tree involves visiting the left subtree, then the right subtree, and finally the root node. This order ensures that we process child nodes before their parent nodes, making it useful for operations where child nodes need to be handled before their parents.

# Approach
We use a recursive helper function to achieve postorder traversal. The function first recursively traverses the left subtree, followed by the right subtree, and finally processes the root node. The values are stored in an array, which is dynamically updated using an index pointer.

# Complexity
- **Time complexity:** The time complexity is $$O(n)$$, where $$n$$ is the number of nodes in the binary tree. This is because each node is visited exactly once.

- **Space complexity:** The space complexity is $$O(n)$$. This accounts for the space required to store the traversal result and the space used by the call stack during the recursive function calls. In the worst case, the depth of the recursion stack can reach $$O(n)$$ if the tree is skewed.

# Code
```c
void postorderHelper(struct TreeNode* root, int* result, int* index) {
    if (root == NULL) {
        return;
    }
    postorderHelper(root->left, result, index);
    postorderHelper(root->right, result, index);
    result[(*index)++] = root->val;
}
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(100 * sizeof(int));
    *returnSize = 0;
    postorderHelper(root, result, returnSize);
    
    return result;
/*
	Author   : Diya Maity
	Date     : Sunday, August 25, 2024, 10:50 PM	
	LinkedIn : https://www.linkedin.com/in/diyamity
	GitHub   : https://github.com/diya-2003
	LeetCode : https://leetcode.com/u/diyamaity        		
    */
}
