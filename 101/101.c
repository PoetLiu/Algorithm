typedef struct _list_node {
    void *val;
    struct _list_node *next;
}list_node;

typedef struct _queue {
    int size;
    struct _list_node *head;
    struct _list_node *tail;
}queue;

void en_queue(queue *q, void *val) {
    list_node *new = NULL;
    
    if (!q)
        return;
        
    new = calloc(1, sizeof *new);
    if (!new)
        return;
    new->val    = val;
    if (q->tail)
        q->tail->next   = new;
    if (!q->head)
        q->head = new;
    q->tail = new;
    q->size++;
    return;
}

void *de_queue(queue *q) {
    list_node *tmp = NULL, *tmp1 = NULL;
    
    if (!q || !q->size)
        return NULL;
    tmp = q->head;
    tmp1    = tmp->val;
    q->head    = q->head->next;
    q->size--;
    if (!q->size)
       q->tail  = NULL;
    free(tmp);
    return tmp1;
}

void pruge_queue(queue *q) {
    list_node *now = NULL, *next = NULL;
    if (!q || !q->size)
        return;
    for (now = q->head, next = now->next; now; now = next, next = next ? next->next : NULL)
        free(now);
    memset(q, 0, sizeof *q);
    return;
}

typedef bool (*NODE_CMP_FUNC)(void *left, void *right);
bool list_node_cmp(list_node *left, list_node *right)
{
    if (!left && !right)
        return true;
    if (!left || !right)
        return false;
    return left->val == right->val;
}

bool queue_is_symmetric(queue *q, NODE_CMP_FUNC cmp)
{
    void **buf = NULL;
    list_node *now = NULL;
    int i = 0, j = 0;
    
    if (!q || !cmp)
        return false;
    
    if (q->size <= 1)
        return true;
    buf = calloc(q->size, sizeof *buf);
    if (!buf)
        return false;
    
    for (now = q->head; now; now = now->next)
        buf[i++]    = now->val;
    
    for (j = i/2 - 1; j >= 0; j--) {
        if (!cmp(buf[j], buf[i-j-1])) {
            free(buf);
            return false;
        }
    }
    free(buf);
    return true;
}

bool levelOrder_check(struct TreeNode *p) {
    int current = 0, next = 0, ret = true;
    queue q;
    
    if (!p)
        return true;
    memset(&q, 0, sizeof(q));
    en_queue(&q, p);
    
    while (q.size) {    // there is node exist in next level.
        current = 0;
        next    = q.size;
        while (current < next) {    // there is node exist in current level.
            current++;
            struct TreeNode *tmp = de_queue(&q);
            if (!tmp)
                continue;
            en_queue(&q, tmp->left);
            en_queue(&q, tmp->right);
        }
        if (!queue_is_symmetric(&q, list_node_cmp)) {
            ret = false;
            goto ret;
        }
    }
ret:
    pruge_queue(&q);
    return ret;
}
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSymmetric(struct TreeNode* root) {
    return levelOrder_check(root);
}
