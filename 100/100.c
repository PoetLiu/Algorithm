/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 bool preOrder(struct TreeNode *p, struct TreeNode *q)
 {
    if (!p && !q)
        return true;
    if (!p || !q)
        return false;
    if (p->val != q->val) 
        return false;
    if (preOrder(p->left, q->left) == false)
        return false;
    if (preOrder(p->right, q->right) == false)
        return false;
    return true;
 }
 
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    return preOrder(p, q);
}
