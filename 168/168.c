char* convertToTitle(int n) {
    int tmp = n-1, i = 0, nums = 2; 
    char *p = NULL;
    
    while (tmp/26)
        nums++, tmp = tmp/26 - 1;

    p   = calloc(nums, sizeof *p);
    if (!p)
        return NULL;
    for (i = nums-2, tmp = n-1; i >= 0; i--, tmp = tmp/26 - 1) 
        p[i]    = tmp%26 + 'A';

    return p;
}
