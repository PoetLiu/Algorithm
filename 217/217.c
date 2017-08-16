bool containsDuplicate(int* nums, int numsSize) {
    int i = 0, j = 0;
    
    if (!nums || numsSize <= 1)
        return false;
    for (i = 0; i < numsSize; i++) {
        for (j = i+1; j < numsSize; j++) {
            if (nums[j] == nums[i])
                return true;
        }
    }
    return false;
}
