char* longestCommonPrefix(char** strs, int strsSize) {
    int i = 0, j = 0;
    char *s = NULL;
    
    if (strsSize <= 0)
        return "";
        
    if (strsSize == 1)
        return strs[0];
    
    for (i = 0; strs[0][i] != '\0'; i++) {
        for (j = 1; j < strsSize; j++) {
            if (strs[j][i] != strs[0][i])
                break;
        }
        if (j != strsSize)
            break;
    }
    if (i == 0)
        return "";
    
    s   = malloc(sizeof *s * (i+1));
    if (!s)
        return "";
    for (j = 0; j < i; j++)
        s[j]    = strs[0][j];
    s[i]    = '\0';
    return s;
}
