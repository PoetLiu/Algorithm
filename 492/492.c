/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* constructRectangle(int area, int* returnSize) {
    int *res = calloc(2, sizeof(*res)), i = 0, quot = 0;
    
    if (!res || !returnSize)
        goto ret;
    *returnSize = 2;
    res[0]  = area;
    res[1]  = 1;
    
    for (i = sqrt(area); i >= 1; i--) {
        if (area%i == 0)
            break;
    }
    if (i > 0) {
        quot    = area/i;
        res[0]  = (i >= quot ? i : quot);
        res[1]  = (i >= quot ? quot : i);
    }
    
ret:
    return res;
}
