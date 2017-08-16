int thirdMax(int* nums, int numsSize) {
    long long maxs[3] = {LLONG_MIN, LLONG_MIN, LLONG_MIN}, i = 0, j = 0;
    
    if (!nums || numsSize < 1)
        return INT_MIN;
    
    for (i = 0; i < numsSize; i++) {
        for (j = 2; j >= 0; j--) {
            if (nums[i] > maxs[j]) { 
                if (j > 0)
                    memmove(maxs, maxs+1, j*sizeof(long long));
                maxs[j] = nums[i];
                break;
            } else if (nums[i] == maxs[j]) {
                break;
            }
        }
    }
    
    return (maxs[0] != LLONG_MIN) ? maxs[0] : maxs[2];
}
