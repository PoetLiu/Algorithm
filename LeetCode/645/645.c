int cmpFunc(int *a, int *b)
{
    return *a-*b;
}
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findErrorNums(int* nums, int numsSize, int* returnSize) {
    int *ret = calloc(2, sizeof(*ret)), i;
    
    qsort(nums, numsSize, sizeof(*nums), cmpFunc);
    for (i = 1; i < numsSize; i++) {
        if (nums[i] == nums[i-1]) {
            ret[0]  = nums[i];
            memmove(&nums[i], &nums[i+1], sizeof(*nums)*(numsSize-i-1));
            break;
        }
    }
    
    for (i = 0; i < numsSize; i++) {
        if (nums[i] != i+1) {
            ret[1]  = i+1;
            break;
        }
    }
            
ret:
    *returnSize = 2;
    return ret;
}
