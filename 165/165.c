int compareVersion(char* version1, char* version2) {
    char *tmp1 = version1, *tmp2 = version2;
    int res = 0;
    
    while (tmp1 || tmp2) {
        res = (tmp1?atoi(tmp1):0) - (tmp2?atoi(tmp2):0);
        if (res > 0)
            return 1;
        if (res < 0)
            return -1;
            
        if (tmp1 && (tmp1 = strstr(tmp1, ".")))
            tmp1++;
        
        if (tmp2 && (tmp2 = strstr(tmp2, ".")))
            tmp2++;
    }
    return 0;
}
