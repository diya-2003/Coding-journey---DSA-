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
