struct NumArray {
    int *nums;
    int size;
};

/** Initialize your data structure here. */
struct NumArray* NumArrayCreate(int* nums, int numsSize) {
    struct NumArray *res = malloc(sizeof *res);
    if (!nums || numsSize <= 0 || !res)
        return NULL;
    res->nums   = malloc(sizeof *nums * numsSize);
    if (!(res->nums))
        return NULL;
    memcpy(res->nums, nums, sizeof *nums * numsSize);
    res->size   = numsSize;
    return res;
}

int sumRange(struct NumArray* numArray, int i, int j) {
    int k = 0, res = 0;
    if (!numArray || !(numArray->nums))
        return 0;
        
    for (k = i; k <= j; k++) 
        res += numArray->nums[k];
    return res;
}

/** Deallocates memory previously allocated for the data structure. */
void NumArrayFree(struct NumArray* numArray) {
    if (!numArray)
        return;
    if (numArray->nums)
        free(numArray->nums);
    free(numArray);
    return;
}

// Your NumArray object will be instantiated and called as such:
// struct NumArray* numArray = NumArrayCreate(nums, numsSize);
// sumRange(numArray, 0, 1);
// sumRange(numArray, 1, 2);
// NumArrayFree(numArray);
