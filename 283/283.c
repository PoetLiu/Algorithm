void moveZeroes(int* nums, int numsSize) {
    int i = numsSize-1, cnt = 0;
    if (!nums || numsSize <= 1)
        return;
    
    for (; i >= 0; i--) {
        if (nums[i] != 0) {
            cnt++;
            continue;
        }
        memmove(nums+i, nums+i+1, cnt*sizeof(int));
        nums[i+cnt] = 0;
    } 
    return;
}
