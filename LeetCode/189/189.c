void rotate(int* nums, int numsSize, int k) {
    int i = 0, tmp = 0; 
    int *buf = NULL;
    
    if (!nums || numsSize <= 0 || k <= 0 || k%numsSize == 0)
        return;

    k   = k%numsSize;
    buf = calloc(k, sizeof *buf);
    if (!buf)
        return;
    memcpy(buf, nums+numsSize-k, k * sizeof *buf);
    memmove(nums+k, nums, (numsSize-k) * sizeof *buf);
    memcpy(nums, buf, k * sizeof *buf);
    free(buf);
    return;
}
