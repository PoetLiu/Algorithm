int removeElement(int* nums, int numsSize, int val) {
    int res = 0, i = 0, j = 0, tmp = 0;
    if (!nums)
        return 0;

    for (i = 0; i < numsSize; i++) {
        for (j = i; j < numsSize; j++) {
            if (nums[j] != val) {
                tmp = nums[i];
                nums[i] =  nums[j];
                nums[j] = tmp;
                res++;
                break;
            }
        }
    }

    return res;
}
