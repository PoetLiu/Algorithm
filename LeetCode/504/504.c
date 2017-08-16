
#define BASE_NUM    7
char* convertToBase7(int num) {
    int bits[12] = {0}, bitsCnt = 0, tmp = abs(num), i = 0, j = 0, sign = num < 0 ? 1 : 0;
    char *res = NULL;
    
    if (tmp == 0) {
        bits[bitsCnt++] = 0;
    }
    while (tmp) {
        bits[bitsCnt++] = tmp%BASE_NUM;
        tmp /= BASE_NUM;
    }
    
    res = calloc(1, sizeof *res * (bitsCnt+1+sign));
    if (!res)
        goto ret;
    if (sign)
        res[j++]    = '-';
    for (i = bitsCnt-1; i >= 0 ; i--) {
        res[j++] = bits[i] + '0';
    }
ret:
    return res;
}
