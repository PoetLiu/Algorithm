int findComplement(int num) {
    int i =30, res = 0, skip = 1; 
    
    for (i; i >= 0; i--) {
        if ((1 << i) & num) {
            skip    = 0;
        } else if (skip) {
            continue;
        } else {
            res |= (1 << i);
        }
    }
    
ret:
    return res;
}
