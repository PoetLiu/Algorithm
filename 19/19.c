/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int len = 0, i = 0;
    struct ListNode *tmp = head, *del = NULL;
    
    if (!head || n <= 0)
        return head;
        
    while (tmp)  {
        len++;
        tmp = tmp->next;
    }
    
    if (len == n) {
        del = head;
        head    = head->next;
        goto ret;
    }
    
    for (tmp = head, i = 0; tmp != NULL; i++, tmp=tmp->next) {
        if (i == len-n-1) {
            del = tmp->next;
            tmp->next   = del->next;
            goto ret;
        }
    }
    
ret:
    if (del)
        free(del);
    return head;
}
