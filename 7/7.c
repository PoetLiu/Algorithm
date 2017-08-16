int reverse(int x) {
    int tmp = x, tmp1 = x, digits = 1, i = 0;
    long long res = 0;
    
    while (tmp /= 10)
        digits++;
        
    if (digits == 1)
        return x;
 
    for (i = 1; i <= digits; i++) {
        tmp = tmp1 % 10;
        tmp1    /= 10;
        if (i != 1)
            res *= 10;
        res += tmp;
        if (i < digits && (res > INT_MAX/10 || res < INT_MIN/10))
            return 0;
    }
    
    return res;
} 
