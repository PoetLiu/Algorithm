void quickSort(int *nums, int start, int end) 
{
    int ref = start, right = end, left = ref, tmp = 0;
    if (!nums || start == end || start > end) {
        return;
    }
    
    while (left != right) {
        while (!(nums[right] < nums[ref]) && right > left)
            right--;
        while (!(nums[left] > nums[ref]) && left < right)
            left++;
        if (left < right) {
            tmp  = nums[left];
            nums[left]  = nums[right];
            nums[right] = tmp;
        }
    }
    
    tmp  = nums[ref];
    nums[ref]  = nums[right];
    nums[right] = tmp;
    if (right > start)
        quickSort(nums, start, right-1);
    if (right < end)
        quickSort(nums, right+1, end);
}

int arrayPairSum(int* nums, int numsSize) {
    int sum = 0, i;
    quickSort(nums, 0, numsSize-1);
    
    for (i = 0; i < numsSize; i += 2) {
        sum += nums[i];
    }
    return sum;
}
