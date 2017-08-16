int cmpFunc(int *a, int *b)
{
    return *a - *b;
}
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDuplicates(int* nums, int numsSize, int* returnSize) {
    int i = 0, j = 0;
    int *ret    = calloc(numsSize/2, sizeof(*nums));
    
    for (i = 0; i < numsSize; i++) {
        if (nums[abs(nums[i])-1] > 0) {
            nums[abs(nums[i])-1] *= -1;
        } else {
            ret[j++]    = abs(nums[i]);
        }
    }
    *returnSize = j;
    return ret;
}
