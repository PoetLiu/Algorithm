/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode *now = NULL, *next = NULL;
    if (!head)
        goto ret;
    
    for (now = head, next = head->next; now != NULL && next != NULL;) {
        if (now->val == next->val) {
            now->next   = next->next;
            free(next);
            next    = now->next;
            continue;
        }
        now = next;
        next = next->next;
    }
ret:
    return head;
}
