bool checkPath(struct ListNode* head, struct TreeNode* root) {

    if (!head) return true;
    if (!root) return false;
    if (head->val == root->val) {
        return checkPath(head->next, root->left) || checkPath(head->next, root->right);
    }
    return false;
}
bool isSubPath(struct ListNode* head, struct TreeNode* root) {
    if (!root) return false;
    if (checkPath(head, root)) return true;
    return isSubPath(head, root->left) || isSubPath(head, root->right);
}
