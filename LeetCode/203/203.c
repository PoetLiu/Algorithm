/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode *now = NULL, *prev = NULL;
    if (!head)
        return NULL;
    
    while (head && (head->val == val)) {
        now = head->next;
        free(head);
        head    = now;
    }
    
    if (!head)
        return NULL;
    
    for (prev = head, now = prev->next; prev != NULL && now != NULL;) {
        if (now->val == val) {
            prev->next = now->next;
            free(now);
            now = prev->next;
            continue;
        }
        prev    = prev->next;
        now = prev->next;
    }
    return head;
}
