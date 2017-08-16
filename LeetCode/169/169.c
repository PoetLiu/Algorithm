int majorityElement(int* nums, int numsSize) {
    int i = 0, j = 0, dupCnt = 1;
    
    if (!nums)
        return 0;
        
    if (numsSize <= 1)
        return nums[0];
       
    for (i = 0; i < numsSize; i++) {
        if (i && nums[i] == nums[i-1])
            continue;
        for (j = i+1, dupCnt = 1; j < numsSize; j++) {
            if (nums[j] == nums[i])
                dupCnt++;
        }
        if (dupCnt > numsSize/2)
            return nums[i];
    }
    return nums[i];
}
