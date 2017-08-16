void resPush(int **res, int *resSize, int new) 
{
    int i = 0;

    if (*res) {
        for (i; i < *resSize; i++) {
            if (new == (*res)[i])
                return;
        }
    }
    (*resSize)++;
    *res    = realloc(*res, *resSize * sizeof(**res));
    if (!(*res))
        return;
    (*res)[(*resSize)-1]    = new;
}

typedef uint32_t BitMap[INT_MAX/32+(INT_MAX%32>0)];

void BitSet(BitMap m, int b) 
{
    m[b/32] |= 1 << (32-b%32);
    return;
}

bool BitTest(BitMap m, int b) 
{
    return (m[b/32] & 1 << (32-b%32));
}
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int *res = NULL, i = 0;
    BitMap *m = calloc(1, sizeof(*m));
    
    if (nums1Size < 1 || nums2Size < 1)
        goto ret;
    
    while (i < nums1Size) {
        BitSet(m, nums1[i++]);
    } 
    
    for (i = 0; i < nums2Size; i++) {
        if (BitTest(m, nums2[i]))
            resPush(&res, returnSize, nums2[i]);
    }

ret:
    return res;
}
