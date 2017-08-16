/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *now = head, *next = NULL, *tmp = NULL;
    if (!head || !(head->next))
        return head;
    
    for (next = head->next; next != NULL; now = next, next = tmp) {
        tmp = next->next;
        next->next  = now;
        if (now == head)
            now->next   = NULL;
    }
    return now;
}
