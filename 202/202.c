typedef struct node {
    int val;
    struct node *next;
}Node;

#define LIST_HEAD_INIT(h) ((h)->next=NULL)

int list_node_add(Node *head, Node *new)
{
    Node *tmp = head->next;
    if (!head || !new)
        return -1;
    head->next  = new;
    new->next   = tmp;
    return 0;
}

Node* list_node_new(int val)
{
    Node *new = NULL;
    new = calloc(1, sizeof *new);
    if (!new)
        return NULL;
    new->val    = val;
    return new;
}
    
int list_node_add_new(Node *head, int val)
{
    return list_node_add(head, list_node_new(val));
}

void list_destory(Node *head)
{
    Node *del = head->next, *next = NULL;
    if (!head || !del)
        return;
    for (next = del->next; del != NULL; del = next, next = next?next->next:NULL) {
        free(del);
    }
    return;
}

bool node_val_in_list(Node *head, int val)
{
    Node *p = head->next;
    if (!head)
        return false;
    for (; p != NULL; p = p->next) {
        if (p->val == val)
            return true;
    }
    return false;
}

int sum_digits_square(int n)
{
    int res = 0;
    while (n) {
        res += (n%10)*(n%10);
        n   /= 10;
    }
    return res;
}

bool isHappy(int n) {
    int tmp = 0;
    bool res = false;
    Node head;
    LIST_HEAD_INIT(&head);
    
    while (1) {
        if ((tmp = sum_digits_square(n)) == 1) {
            res =  true;
            goto ret;
        }
        if (node_val_in_list(&head, tmp)) {
            res = false;
            goto ret;
        }
        list_node_add_new(&head, tmp);
        n   = tmp;
    }
    
ret:
    list_destory(&head);
    return res;
}
