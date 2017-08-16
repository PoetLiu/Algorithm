/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElement(int* findNums, int findNumsSize, int* nums, int numsSize, int* returnSize) {
    int *res = calloc(findNumsSize, sizeof(int));
    int i, j;
    
    *returnSize = findNumsSize;
    for (i = 0; i < findNumsSize; i++) {
        j   = 0;
        while (nums[j] != findNums[i])
            j++;
        for (j++; j < numsSize; j++) {
            if (nums[j] > findNums[i]) {
                res[i]  = nums[j];
                break;
            }
        }
        if (j == numsSize)
            res[i]  = -1;
    }
    return res;
}
