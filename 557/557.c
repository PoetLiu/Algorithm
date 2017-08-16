char* reverseWords(char* s) {
    int len = strlen(s), i = 0, j = 0, sub_len = 0;
    char *res = strdup(s);
    
    if (!s || !res)
        goto ret;
    
    for (i = len-1; i >= 0; i--) {
        if (s[i] != ' ') {
            sub_len++;
            if (i != 0) {
                continue;
            }
        }
        for (j = 0; j < sub_len; j++) {
            res[(i==0?-1:i)+1+j]    = s[(i==0?-1:i)+sub_len-j];
        }
        sub_len = 0;
    }
ret:
    return res;
}
