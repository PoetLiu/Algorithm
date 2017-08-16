/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void preOrderInvert(struct TreeNode* p) {
    struct TreeNode *tmp = NULL;
    if (p) {
        tmp = p->left;
        p->left = p->right;
        p->right    = tmp;
        if (p->left)
            preOrderInvert(p->left);
        if (p->right)
            preOrderInvert(p->right);
    }
}
struct TreeNode* invertTree(struct TreeNode* root) {
    preOrderInvert(root);
    return root;
}
