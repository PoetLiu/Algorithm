int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int max = 0, cur = 0, i = 0;
    
    if (!nums || numsSize < 1) {
        goto ret;     
    }   
    
    for (i; i < numsSize; i++) {
        if (nums[i] == 1) {
            cur ++;
        } else {
            cur = 0;
        }
        if (cur > max) {
            max = cur;
        }
    }
ret:
    return max;
}
