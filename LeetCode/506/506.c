#define NUM 10000
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findRelativeRanks(int* nums, int numsSize, int* returnSize) {
    int i = 0, j = 0, idx[NUM] = {0}, cnt = 1, rank = 1;
    char **res = NULL, chr[16] = {0};
    
    *returnSize = numsSize;
    for (i = 1; i < numsSize; i++) {
        for (j = 0; j < cnt; j++) {
            if (nums[i] > nums[idx[j]]) {
                memmove(&idx[j+1], &idx[j], (numsSize-j) * sizeof(idx[0]));
                idx[j]  = i;
                cnt++;
                break;
            }
        }
        if (i == cnt)  {
            idx[cnt++]  = i;
        }
    }
    
    
    res = calloc(1, sizeof *res * numsSize);
    if (!res)
        goto ret;
    for (i = 0; i < numsSize; i++, rank++) {
        switch (rank) {
            case 1:
                res[idx[i]]  = strdup("Gold Medal");
                break;
            case 2:
                res[idx[i]]  = strdup("Silver Medal");
                break;
            case 3:
                res[idx[i]]  = strdup("Bronze Medal");
                break;
            default:
                snprintf(chr, sizeof(chr)-1, "%d", rank);
                res[idx[i]]  = strdup(chr);
                break;
        }
    }
    
ret:
    return res;
}
