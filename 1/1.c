/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int i, j, *p = NULL;
    if (!nums)
        goto ret;
    for (i = 0; i < numsSize; i++) {
        for (j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                p   = malloc(sizeof *p * 2);
                if (!p)
                    goto ret;
                p[0]    = i;
                p[1]    = j;
                break;
            }
        }
    }
    
ret:
    return p;
}
