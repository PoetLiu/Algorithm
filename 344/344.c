char* reverseString(char* s) {
    int len = 0, i = 0;
    char *p = s, tmp = 0;
    
    if (!s)
        goto ret;
    while (*p++ != '\0')
        len++;
    if (len <= 1)
        goto ret;
        
    for (i = 0; i < len/2; i++) {
        tmp     = s[i];
        s[i]    = s[len-i-1];
        s[len-i-1]  = tmp;
    }
ret:
    return s;
}
