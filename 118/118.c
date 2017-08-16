/**
 * Return an array of arrays.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int** columnSizes) {
    int i = 0, j = 0, k = 0; 
    int **res = NULL, *tmp = NULL;

    // alloc for res.
    tmp = calloc(numRows, sizeof(int *));
    if (!tmp)
        goto ret;
    res = (int **)tmp;
    
    tmp = calloc(numRows, sizeof(int));
    if (!tmp)
        goto ret;
    *columnSizes = tmp;
    
    // alloc for each array.
    for (i = 0; i < numRows; i++) {
        tmp  = calloc(i+1, sizeof(int));
        if (!tmp)
            goto ret;
        res[i]  = tmp;
        (*columnSizes)[i]    = i+1;
        res[i][0]   = 1;
        res[i][i]   = 1;
        if (i < 2)
            continue;
        for (j = 1; j < i; j++) 
            res[i][j]   = res[i-1][j-1] + res[i-1][j];
    }
ret:
    return res;
}
