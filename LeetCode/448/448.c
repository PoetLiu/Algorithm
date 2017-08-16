#define PER_CELL_BIT    8
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    unsigned char *bitMap = NULL;
    int i = 0, mapSize = 0, idx = 0;
    int *res = NULL;
    
    if (!nums || numsSize < 1 || !returnSize)
        return NULL;
    
    *returnSize = 0;
    mapSize = numsSize/PER_CELL_BIT + ((numsSize%PER_CELL_BIT) ? 1 : 0);
    bitMap  = calloc(1, mapSize * sizeof *bitMap);
    if (!bitMap)
        return NULL;
    res     = calloc(1, numsSize * sizeof *res);
    if (!res)
        return NULL;
        
    for (i = 0; i < numsSize; i++)  {
        bitMap[(nums[i]-1)/PER_CELL_BIT]    |=  (1 << ((nums[i]-1)%PER_CELL_BIT));
    }

    for (i = 1; i <= numsSize; i++) {
        if (bitMap[(i-1)/PER_CELL_BIT] & (1 << (i-1)%PER_CELL_BIT))
            continue;
        res[(*returnSize)++]  = i;
    }
    if (bitMap)
        free(bitMap);
    return res;
}
