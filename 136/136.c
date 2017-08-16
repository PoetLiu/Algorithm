int singleNumber(int* nums, int numsSize) {
    int i = 0, res = 0;
    if (!nums || numsSize <= 0)
        return 0;
    for (; i < numsSize; i++) {
        res ^= nums[i];
    }
    return res;
}
