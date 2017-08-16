typedef struct _list_node {
      int val;
      int num_digits;
      struct _list_node *next;
}list_node;

typedef struct _Stack {
    int size;
    int total_digits;
    list_node *top;
}Stack;

void stack_pop(Stack *s) {
    list_node *tmp = NULL;
    if (!s || s->size <= 0)
        return;
    tmp = s->top;
    s->top  = s->top->next;
    s->size--;
    s->total_digits -= tmp->num_digits;
    free(tmp);
    return;
}

void stack_push(Stack *s, list_node *new) {
    int tmp = 0;
    if (!s || !new)
        return;
    new->next   = s->top;
    s->top  = new;
    s->size++;
    tmp = new->val;
    new->num_digits = 1;
    while (tmp/10) {
        new->num_digits++;
        tmp /= 10;
    }
    if (tmp < 0)
        new->num_digits++;
    s->total_digits += new->num_digits;
    return;
}

void stack_push_new(Stack *s, int val) {
    list_node *tmp = NULL;
    if (!s)
        return;
    tmp = calloc(1, sizeof *tmp);
    if (!tmp)
        return;
    tmp->val    = val;
    stack_push(s, tmp);
}

char *print_stack(Stack *s) {
    char *tmp = NULL;
    list_node *node = NULL;
    int i = 0, size = 0;
    
    if (!s || !s->size)
        return NULL;
    size    = s->total_digits + (s->size-1)*2 + 1;
    tmp = calloc(size, sizeof *tmp);
    if (!tmp)
        return NULL;
    
    for (node = s->top, i = size-1; i >= 0 && node; node = node->next) {
        i   -= node->num_digits;
        sprintf(tmp+i, "%d", node->val);
        if (i+node->num_digits != size-1)
            tmp[i+node->num_digits] = '-';
        if (i-2 > 0) {
            tmp[i-1] = '>';
            tmp[i-2] = '-';
        }
        i   -= 2;
    }
    
    return tmp;
}

void add_res(char *new, char ***res, int *resSize) {
    (*resSize)++;
    if (*resSize > 1) 
        *res = realloc(*res, (*resSize) * sizeof **res);
    else 
        *res = calloc(1, (*resSize) * sizeof **res);
    (*res)[(*resSize)-1]  = new;
    return;
}

void preOrder(Stack *s, struct TreeNode *p, char ***res, int *resSize) {
    if (!p || !s)
        return;
    stack_push_new(s, p->val);
    if (p->left) {
        preOrder(s, p->left, res, resSize);
        stack_pop(s);
    }
    if (p->right) {
        preOrder(s, p->right, res, resSize);
        stack_pop(s);
    }
    if (!p->right && !p->left)
        add_res(print_stack(s), res, resSize);
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
    Stack s;
    char **res = NULL;
    memset(&s, 0, sizeof(s));
    *returnSize = 0;
    preOrder(&s, root, &res, returnSize);
    return res;
}
