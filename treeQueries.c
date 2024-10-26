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
/*      Author   : Diya Maity
        Date     : Satursday, October 26, 2024, 4:15 PM
        LinkedIn : https://www.linkedin.com/in/diyamity
        GitHub   : https://github.com/diya-2003
        LeetCode : https://leetcode.com/u/diyamaity                     */
