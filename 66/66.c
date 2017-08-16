/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int i = 0, j = 0, resSize = digitsSize;
    int *res = NULL;
    
    if (!digits || !returnSize || digitsSize <= 0)
        return NULL;
    
    // check if need extra space.
    while (digits[i] == 9)
        i++;
    if (i == digitsSize)
        resSize++;
        
    res = calloc(resSize, sizeof *res);
    if (!res) 
        return NULL;
    
    // copy and add.
    res[resSize-1]  = 1;
    for (i = digitsSize-1, j = resSize-1; i >= 0 && j >= 0; i--, j--) {
        res[j]  += digits[i];
        if (res[j] > 9) {
            res[j-1]    += 1;
            res[j]      -= 10;
        }
    }
    
    *returnSize = resSize;
    return res;
}
