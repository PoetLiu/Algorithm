int totalHammingDistance(int* nums, int numsSize) {
    int cnt = 0, i = 0, j = 0, bit_cnt = 0;
    
    if (!nums || numsSize <= 1)
        return 0;

    for (i = 0; i <= 31; i++, bit_cnt = 0) {
        for (j = 0; j < numsSize; j++) {
            bit_cnt += ((nums[j] >> i) & 1);
        }
        cnt += bit_cnt * (numsSize-bit_cnt);
    }
    return cnt;
}
