char* addBinary(char* a, char* b) {
    int i = 0, j = 0, k = 0, lena = 0, lenb = 0, len = 0;
    char *tmp = NULL;
    
    if (!a || !b || a[0] == '\0' || b[0] == '\0')
        return NULL;
    
    while (a[lena] != '\0')
        lena++;
    while (b[lenb] != '\0')
        lenb++;
    
    len   = lena > lenb ? lena : lenb;
    tmp = calloc(len+2, sizeof *tmp);
    if (!tmp)
        return NULL;
    tmp[0]  = '0';
    strncpy(tmp+1, lena>lenb?a:b, len+1);
    
    for (i = lena-1, j = lenb-1, k = len; i >= 0 && j >= 0; i--, j--, k--)
        tmp[k]  += (lena>lenb?b[j]:a[i]) - '0';

    for (k = len; k >= 0; k--) {
        if (tmp[k] >= '2') {
            tmp[k] -= 2;
            tmp[k-1] += 1;
        }
    }

    if (tmp[0] == '0')
        memmove(tmp, tmp+1, sizeof *tmp *(len+1));
    return tmp;
}
