int titleToNumber(char* s) {
    int len = 0, i = 0, res = 0, tmp = 1;
    
    if (!s)
        return 0;
        
    while (s[len] != '\0')
        len++;
        
    for (i = len-1; i >= 0; i--, tmp*=26) {
        if (s[i] >= 'A' && s[i] <= 'Z')
            res += (s[i] - 'A' + 1) * tmp;
        else if (s[i] >= 'a' && s[i] <= 'z')
            res += (s[i] - 'a' + 1) * tmp;
    }
    return res;
}
