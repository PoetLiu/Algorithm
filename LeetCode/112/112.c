/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool preOrderSum(struct TreeNode *p, int *res, int sum) {
    if (!p) 
        return false;
    *res += p->val;
    if (p->left) {
        if (preOrderSum(p->left, res, sum))
            return true;
        *res -= p->left->val;
    } 
    if (p->right) {
        if (preOrderSum(p->right, res, sum))
            return true;
        *res -= p->right->val;
    } 
    if (!p->left && !p->right && *res == sum) 
            return true;
    if (*res == p->val)
        return false;
    return false;
}

bool hasPathSum(struct TreeNode* root, int sum) {
    int res = 0;
    return preOrderSum(root, &res, sum);
}
