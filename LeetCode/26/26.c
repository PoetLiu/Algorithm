int removeDuplicates(int* nums, int numsSize) {
    int i = 0, tmp = 0, cnt = 0; 
    if (!nums)
        return 0;
    if (numsSize <= 1)
        return numsSize;
        
    for (i = 1, tmp = nums[0]; i < numsSize; i++) {
        if (nums[i] == tmp) {
            cnt++;
            if (i+1 < numsSize)
                continue;
        } 
        if (cnt) {
            memmove(nums+i-cnt, nums+i, (numsSize-i)*sizeof(int));
            i-=cnt, numsSize-=cnt, cnt = 0;
        }
        tmp = nums[i];
    }
    return numsSize;
}
