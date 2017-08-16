/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void preOrder(struct TreeNode *p, int *max, int *cnt) {
    if (!p)
        return;
    (*cnt)++;
    if (p->left) {
        preOrder(p->left, max, cnt);
        (*cnt)--;
    }
    if (p->right) {
        preOrder(p->right, max, cnt);
        (*cnt)--;
    }
    if (!p->left && !p->right && *cnt > *max)
        *max    = *cnt;
    return;
}
int maxDepth(struct TreeNode* root) {
    int max = 0, cnt = 0;
    preOrder(root, &max, &cnt);
    return max;
}
