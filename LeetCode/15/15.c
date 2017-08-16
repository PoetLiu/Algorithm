int solutionIsExist(int **res, int resNum, int i, int j, int k)
{
    int m = 0, n = 0, findi = 0, findj = 0, findk = 0;
    if (!res)
        return 0;
    
    for (m = 0; m < resNum; m++) {
        findi   = 0;
        findj   = 0;
        findk   = 0;
        for (n = 0; n < 3; n++) {
            if (i == j && j == k) {
                if (res[m][n] == i) {
                    findi++;
                    continue;
                } else {
                    break;
                }
            }
            
            if (res[m][n] == i)
                findi   = 1;
            if (res[m][n] == j)
                findj   = 1;
            if (res[m][n] == k)
                findk   = 1;
        }
        if (findi + findj + findk == 3)
            return 1;
    }
    return 0;
}

int ** addSolution(int **res, int *resNum, int i, int j, int k)
{
    int **p = NULL, *nums = NULL;
    
    if (solutionIsExist(res, *resNum, i, j, k))
        return res;
    (*resNum)++;
    if (res == NULL)
        p   = malloc(sizeof(int *));
    else
        p   = realloc(res, sizeof(int *)*(*resNum));
    
    if (!p)
        goto err;
    nums    = malloc(sizeof(int)*3);
    if (!nums)
        goto err;
    p[*resNum-1]    = nums;
    p[*resNum-1][0] = i;
    p[*resNum-1][1] = j;
    p[*resNum-1][2] = k;
    return p; 
    
err:
    if (p)
        free(p);
    if (nums)
        free(nums);
    *resNum = 0;
    return NULL;
}

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize) {
    int **res   = NULL;
    int i = 0, j = 0, k = 0, resNum = 0;
      
    if (!nums || !returnSize)
        goto res;
    for (i = 0; i < numsSize; i++) {
        for (j = 0; j < numsSize && j != i; j++) {
            for (k = 0; k < numsSize && k != i && k != j; k++) {
                if (nums[i] + nums[j] + nums[k] == 0)
                    res = addSolution(res, &resNum, nums[i], nums[j], nums[k]);
            }
        }
    }
    
    *returnSize = resNum;
res:
    return res;
}
