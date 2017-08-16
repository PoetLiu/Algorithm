int searchInsert(int* nums, int numsSize, int target) {
    int res = 0, i = 0;
    
    if (!nums || numsSize < 1)
        goto ret;

    for (i; i < numsSize; i++) {
        if (target == nums[i] || target < nums[i]) {
            res = i;
            goto ret;
        }
    }
    
    res = i;
ret:
    return res;
}
