int myAtoi(char* str) {
    char *p = str;
    int numBits = 0, sign = 0;
    long long res = 0;
    if (!str)
        return -1;
        
    while (*p == ' ')
        p++;
    
    while (*p != '\0') {
        if (*p == '-') {
            if (numBits || sign == 1 || sign == 2)
                break;
            sign    = 2;
        } else if (*p >= '0' && *p <= '9') {
            if (res > INT_MAX/10 || res == INT_MAX/10 && (*p - '0') >= 7 ) {
                res = INT_MAX;
                break;
            } 
            if (res < INT_MIN/10 || res == INT_MIN/10 && (*p - '0') >= 8) {
                res = INT_MIN;
                break;
            }
            res = res*(numBits ? 10 : 1) + (*p - '0') * (sign == 2 ? -1 : 1);
            numBits++;
        } else if (*p == '+') {
            if (sign == 1 || sign == 2)
                break;
            sign    = 1;
        } else {
            break;
        }
        p++;
    }    
    
    return res;
}
