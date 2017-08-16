typedef struct stack {
    char *top;
    char *bottom;
    size_t size;
    size_t length;
} stack;

stack* stackNew(stack *s, size_t size)
{
    char *p = NULL;
    if (!s)
        return NULL;
    p   = malloc(sizeof *p * size);
    if (!p)
        return NULL;
    s->top  = p;
    s->bottom   = p;
    s->size = size;
    s->length   = 0;
    return s;
}

int stackPush(stack *s, char c)
{
    if (!s)
        return -1;
    if (s->length > s->size)
        return -2;
    *(s->top)   = c;
    s->top++;
    s->length++;
    return 0;
}

bool stackIsEmpty(stack *s)
{
    return s ? s->length==0 : true;
}

char stackPop(stack *s)
{
    char c  = 0;
    if (stackIsEmpty(s))
        return -1;
    s->top--;
    c   = *(s->top);
    s->length--;
    return c;
}

void stackFree(stack *s)
{
    if (!s)
        return;
    if (s->bottom)
        free(s->bottom);
    return;
}

bool isParentheseValid(char cl, char cr)
{
    if (cl == '{' & cr == '}' || cl == '(' && cr == ')' || cl == '[' && cr == ']')
        return true;
    return false;
}

bool isValid(char* s) {
    int len = 0, i = 0, ret = false;
    stack sk;
    
    if (!s)
        return false;
    
    memset(&sk, 0, sizeof(sk));
    while (s[len] != '\0') {
        switch (s[len]) {
            case '(':
            case ')':
            case '{':
            case '}':
            case '[':
            case ']':
                len++;
                break;
            default:
                return false;
        }
    }
        
    if (len%2)
        return false;
    
    if (!stackNew(&sk, len)) 
        return false;
        
    for (i = 0; i < len; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stackPush(&sk, s[i]);
        } else if (!isParentheseValid(stackPop(&sk), s[i])) {
                ret = false;
                goto ret;
        }
    }
    ret = stackIsEmpty(&sk) ? true : false;
ret: 
    stackFree(&sk);
    return ret;
}
