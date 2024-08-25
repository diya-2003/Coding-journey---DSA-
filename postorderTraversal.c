#include <stdio.h>
#include <stdlib.h>


// Helper function to perform postorder traversal
void postorderHelper(struct TreeNode* root, int* result, int* index) {
    if (root == NULL) {
        return;
    }
    
    // Recur on the left subtree
    postorderHelper(root->left, result, index);
    
    // Recur on the right subtree
    postorderHelper(root->right, result, index);
    
    // Visit the root node
    result[(*index)++] = root->val;
}

// Function to return the postorder traversal of a binary tree
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    // Allocate memory for storing the result
    int* result = (int*)malloc(100 * sizeof(int));
    *returnSize = 0;
    
    // Perform the postorder traversal
    postorderHelper(root, result, returnSize);
    
    return result;
/*	Author   : Diya Maity
	Date     : Sunday, August 25, 2024, 10:50 PM	
	LinkedIn : https://www.linkedin.com/in/diyamity
	GitHub   : https://github.com/diya-2003
	LeetCode : https://leetcode.com/u/diyamaity        		*/
}
