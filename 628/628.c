int cmpFunc(int *a, int *b)
{
    return *a-*b;
}

int maximumProduct(int* nums, int numsSize) 
{
    int ret1 = 0, ret2 = 0;
    
    qsort(nums, numsSize, sizeof(*nums), cmpFunc);
    ret1    = nums[numsSize-1]*nums[numsSize-2]*nums[numsSize-3];
    if (nums[numsSize-1] <= 0 || nums[0] >= 0)
        return ret1;
    ret2   = nums[0]*nums[1]*nums[numsSize-1];
    return ret1>ret2?ret1:ret2;
}
