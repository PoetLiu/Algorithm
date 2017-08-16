int strStr(char* haystack, char* needle) {
    int i = 0, j = 0;
    
    if (!haystack || !needle)
        return -1;
        
    if (needle[0] == '\0')
        return 0;
        
    while (haystack[i] != '\0') {
        if (haystack[i] == needle[j]) {
            j++;
        } else if (j != 0) {
                i   -= j-1;
                j   = 0;
                continue;
        }
        if (needle[j] == '\0')
            return i-j+1;
        i++;
    }
    return -1;
}
