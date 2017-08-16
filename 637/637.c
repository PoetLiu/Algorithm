/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct _list_node {
    void *val;
    struct _list_node *next;
}list_node;

typedef struct _Queue {
    int size;
    list_node *head;
    list_node *tail;
}Queue;

void *de_queue(Queue *q)
{
    list_node *tmp = NULL;
    void *res = NULL;
    if (!q || !q->size)
        return NULL;
    tmp = q->head;
    q->size--;
    q->head = q->head ? q->head->next : NULL;
    res = tmp->val;
    free(tmp);
    return res;
}

void _en_queue(Queue *q, list_node *new)
{
    int tmp = 0;
    if (!q || !new)
        return;
    if (q->tail)
        q->tail->next   = new;
    if (!q->head)
        q->head = new;
    q->tail = new;
    tmp = new->val;
    q->size++;
    return;
}

void en_queue(Queue *q, void *val)
{
    list_node *new = NULL;
    if (!q)
        return;
    new = calloc(1, sizeof *new);
    if (!new)
        return;
    new->val    = val;
    _en_queue(q, new);
    return;
}

bool queue_is_empty(Queue *q)
{
    return q ? q->size == 0 : true;
}

void print_queue(Queue *q)
{
    list_node *tmp = NULL;
    if (!q || !q->size)
        return;
    for (tmp = q->head; tmp != NULL; tmp = tmp->next)
        printf("%d,", ((struct TreeNode *)(tmp->val)) ? ((struct TreeNode *)(tmp->val))->val : -1);
    printf("\n");
}

void pruge_queue(Queue *q)
{
    list_node *now = NULL, *next = NULL;
    if (!q || !q->size)
        return;
    for (now = q->head, next = now->next; now; now = next, next = next ? next->next : NULL)
        free(now);
    memset(q, 0, sizeof *q);
    return;
}

void queue_add_2_res(Queue *q, double **res, int *resSize)
{
    double sum = 0, size = q->size;
    int i = 0;
    struct TreeNode *n = NULL;
    
    if (queue_is_empty(q))
        return;
    
    (*resSize)++;
    *res = realloc(*res, (*resSize)*sizeof(*res)); 
    if (!*res)
        return;
    
    while (n = de_queue(q)) {
        sum += n->val;
    }
    (*res)[(*resSize)-1]   = (double)(sum / size);
    return;
}

void _levelOrder(struct TreeNode *p, double **res, int *resSize)
{
    Queue q, q1;
    int current = 0;
    int next = 1;
    
    memset(&q, 0, sizeof(q));
    memset(&q1, 0, sizeof(q1));
    
    if (!p)
        return;
    en_queue(&q, p);
    
    while (q.size) { // there is node exist in next level.
        current = 0;
        next = q.size;
        while (current < next) { // there is node exist in current level.
            struct TreeNode *p  = de_queue(&q);
            en_queue(&q1, p);
            if (p->left)
                en_queue(&q, p->left);
            if (p->right)
                en_queue(&q, p->right);
            current++;
        }
        queue_add_2_res(&q1, res, resSize), pruge_queue(&q1);
    }
    pruge_queue(&q);
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
double* averageOfLevels(struct TreeNode* root, int* returnSize) {
    double *res = NULL;
    
    _levelOrder(root, &res, returnSize);
    return res;
}
