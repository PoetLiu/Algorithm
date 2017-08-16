char* addStrings(char* num1, char* num2) {
    char *res = NULL, *tmp = NULL;
    int size = 0, i = 0, j = 0, l = 0, sum = 0, len1 = strlen(num1), len2 = strlen(num2);

    if (!num1 && !num2)
        return NULL;
        
    if (!num1)
        return strdup(num2);
    
    if (!num2)
        return strdup(num1);
    
    size    = len1 >= len2 ? len1+2 : len2+2;
    tmp     = len1 >= len2 ? num2 : num1;
    res = calloc(1, sizeof *res * size);
    if (!res)
        return NULL;
    res[0]  = '0';   
    strncpy(res+1, len1>=len2?num1:num2, len1>=len2?len1:len2);
    
    for (i = size-2, j = strlen(tmp)-1; i >= 0, j >= 0; i--, j--) {
        sum = res[i] - '0' + tmp[j] - '0';
        if (sum > 9) {
            res[i]    = sum - 10 + '0';
            for (l = i - 1; l >= 0; l--) {
                if (res[l] != '9') {
                    res[l]++;
                    break; 
                } else {
                    res[l]  = '0';
                }
            }
        } else {
            res[i]  = sum + '0';
        }
    }
    if (res[0] == '0')
        strncpy(res, res+1, size-1);
    return res;
}
