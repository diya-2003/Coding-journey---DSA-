/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

void postorderTraversal(struct Node* root, int** result, int* index) {
    if (root == NULL) return;
    
    for (int i = 0; i < root->numChildren; i++) {
        postorderTraversal(root->children[i], result, index);
    }
    
    (*result)[(*index)++] = root->val;
}

int countNodes(struct Node* root) {
    if (root == NULL) return 0;
    
    int count = 1;
    for (int i = 0; i < root->numChildren; i++) {
        count += countNodes(root->children[i]);
    }
    
    return count;
}

int* postorder(struct Node* root, int* returnSize) {
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }
    
    int totalNodes = countNodes(root);
    int* result = (int*)malloc(sizeof(int) * totalNodes);
    int index = 0;
    
    postorderTraversal(root, &result, &index);
    
    *returnSize = totalNodes;
    return result;
}
/*	Author   : Diya Maity
	Date     : Sunday, August 25, 2024, 10:50 PM	
	LinkedIn : https://www.linkedin.com/in/diyamity
	GitHub   : https://github.com/diya-2003
	LeetCode : https://leetcode.com/u/diyamaity        		*/
