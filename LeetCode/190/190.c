uint32_t reverseBits(uint32_t n) {
    uint32_t res = 0;
    int i = 0; 
    
    for (i; i < 32; i++) {
        if ((1 << i) & n) {
            res |= (1 << (32-i-1));
        }
    }
    return res;
}
