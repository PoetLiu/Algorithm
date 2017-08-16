/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* newNode(void)
{
    return calloc(1, sizeof(struct ListNode));
}

// 0:ok 1:err
int addNode(struct ListNode *head, struct ListNode *node)
{
    struct ListNode *tmp = head;
    if (!node || !head)
        goto err;
        
    while (tmp->next)
        tmp = tmp->next;
        
    tmp->next   = node;
    return 0;
err:
    return 1;
}

// make sure all node have single digit.
struct ListNode* listAdjust(struct listNode *l)
{
    struct ListNode *tmp = l;
    int needCarry   = 0;
    
    while (tmp->next) {
        if (needCarry) {
            needCarry   = 0;
            tmp->val++;
        }
        if (tmp->val > 9) {
            needCarry   = 1;
            tmp->val    %= 10;
        }
        tmp = tmp->next;
    }
    
    if (needCarry)
        tmp->val++;
    if (tmp->val > 9) {
        tmp->val    %= 10;
        tmp = newNode();
        if (!tmp)
            goto ret;
        tmp->val    = 1;
        addNode(l, tmp);
    }
    
ret:
    return l;
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *lres = NULL, *tmp1 = NULL, *tmp2 = NULL, *tmp3 = NULL;
    
    if (!l1 || !l2)
        goto ret;
    tmp1    = l1;
    tmp2    = l2;
    while (tmp1 || tmp2) {
        tmp3    = newNode();
        if (!tmp3)
            goto ret;
        tmp3->val   = (tmp1 ? tmp1->val : 0) + (tmp2 ? tmp2->val : 0);
        if (!lres)
            lres    = tmp3;
        else
            addNode(lres, tmp3);
        tmp1    = tmp1 ? tmp1->next : NULL;
        tmp2    = tmp2 ? tmp2->next : NULL;
    }

ret:
    return listAdjust(lres);
}
