#define NUM INT_MAX
#define BIT_MAP_ITEM_TYPE   uint32_t
#define ITEM_BITS           (sizeof(BIT_MAP_ITEM_TYPE)*8)
typedef BIT_MAP_ITEM_TYPE   BitMap[NUM/ITEM_BITS+(NUM%ITEM_BITS?1:0)];

static inline void bit_set(BitMap m, int num)
{
    m[num/ITEM_BITS]    |= (1 << (ITEM_BITS-(num%ITEM_BITS)-1));
    return;
}

static inline bool bit_test(BitMap m, int num)
{
    return m[num/ITEM_BITS] & (1 << (ITEM_BITS-(num%ITEM_BITS))-1);
}

int missingNumber(int* nums, int numsSize) {
    BitMap *m = calloc(1, sizeof(BitMap));
    int i = 0;
    
    if (!nums || numsSize < 1) {
        return INT_MIN;
    }
    
    for (i = 0; i < numsSize; i++) {
        bit_set(m, nums[i]);
    }
    
    for (i = 0; i < numsSize; i++) {
        if (bit_test(m, i) == false)
            return i;
    }
    return i;
}
