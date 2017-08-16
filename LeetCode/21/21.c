/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *p1 = l1, *p2 = l2, *tmp = NULL, *prev = l1;
    if (!l1)
        return l2;
    if (!l2)
        return l1;
    
    for (; p2 != NULL;) {
        if (!p1) {
            prev->next  = p2;
            break;
        }
        if (p2->val <= p1->val) {
            if (p1 == l1) 
                l1  = p2;
            else
                prev->next  = p2;
            prev    = p2;
            tmp   = p2->next;
            p2->next    = p1;
            p2  = tmp;
            continue;
        }
        prev = p1, p1 = p1->next;
    }
    return l1;
}
