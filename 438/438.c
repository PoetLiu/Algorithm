#define PRE_ALLOC_MEM_SIZE 200
int buildStrMap(char *s, int len)
{
    int map = 0, i = 0;
    if (!s)
        return -1;
    for (i = 0; i < len; i++) 
        map |= (1 << (s[i]-'a'));
    return map;
}

void appendRes(int **res, int *resSize, int new)
{
    if (!resSize || !res)
        return;
    *resSize    = *resSize + 1;
    if (!*res)
        *res = malloc(PRE_ALLOC_MEM_SIZE * sizeof **res);
    if (*resSize > PRE_ALLOC_MEM_SIZE)
        *res = realloc(*res, *resSize * sizeof **res);
    (*res)[*resSize-1]    = new;
    return;
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findAnagrams(char* s, char* p, int* returnSize) {
    int pMap = 0, tmpMap = 0, sLen = strlen(s), pLen = strlen(p), i = 0;
    int *res = NULL;
    if (!s || !p || !returnSize)
        return NULL;
        
    *returnSize = 0;  
    pMap    = buildStrMap(p, pLen);
    for (i = 0; i < sLen && sLen-i >= pLen; i++) {
        if (pMap == buildStrMap(s+i, pLen))
            appendRes(&res, returnSize, i);
    }
    return res;
}
