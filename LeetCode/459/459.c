bool repeatedSubstringPattern(char* str) {
    int len = strlen(str), i = 0, j = 0;
    
    if (!str || len <= 1)
        return false;
    
    for (i = 1; i <= (len/2); i++) {
        if (len%i)
            continue;
        for (j = 1; j < len/i; j++) {
            if (!strncmp(str, str+j*i, i))
                continue;
            else
                break;
        }
        if (j == len/i)
            return true;
    }
    return false;
}
