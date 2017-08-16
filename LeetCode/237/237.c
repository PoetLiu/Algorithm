/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    struct ListNode *tmp = node, *prev = NULL;
    if (!node || !node->next)
        return;
    while (tmp->next) {
            tmp->val    = tmp->next->val;
            prev    = tmp;
            tmp = tmp->next;
    }
    prev->next  = NULL;
    free(tmp);
    return;
}
