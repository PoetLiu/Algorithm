int lengthOfLastWord(char* s) {
    int len = 0, res = 0, i = 0;
    char *tmp = s;
    
    if (!s || s[0] == '\0')
        return 0;
        
    while (s[len] != '\0')
        len++;
        
    for (i = len-1; i >= 0; i--) {
        if (s[i] != ' ') {
            res++;
        } else if (res != 0) {
            goto ret;
        }
    }

ret:
    return res;
}
