/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void preOrderDepth(struct TreeNode *p, int *m, int *cnt) {
    if (!p)
        return;
    (*cnt)++;
    if (p->left) {
        preOrderDepth(p->left, m, cnt);
        (*cnt)--;
    }
    if (p->right) {
        preOrderDepth(p->right, m, cnt);
        (*cnt)--;
    }
    
    if (!p->left && !p->right && (*cnt < *m || *m == 0)) 
            *m = *cnt;
    return;
}

int minDepth(struct TreeNode* root) {
    int min = 0, cnt = 0;
    preOrderDepth(root, &min, &cnt);
    return min;
}
