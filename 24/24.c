/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode *now = head, *next = NULL, *prev = head;
    if (!head || !head->next)
        return head;
    
    for (next = now->next; next != NULL; prev = next->next, now = now->next, next = now->next) {
        if (prev != head)
            prev->next  = next;
        else
            head    = next;
        now->next   = next->next;
        next->next  = now;
        if (now->next == NULL)
            break;
    }
    return head;
}
