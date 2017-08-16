int romanCharToInt(char c)
{
    switch (c) {
        case 'i':
        case 'I':
            return 1;
        case 'v':
        case 'V':
            return 5;
        case 'x':
        case 'X':
            return 10;
        case 'l':
        case 'L':
            return 50;
        case 'c':
        case 'C':
            return 100;
        case 'd':
        case 'D':
            return 500;
        case 'm':
        case 'M':
            return 1000;
        default:
            break;
    }
    return 0;
}

int romanToInt(char* s) {
    int res = 0, i = 0, len = 0;
    char *p = s;
    
    if (!s || s[0] == '\0')
        return 0;
    while (*p == ' ')
        p++;
    
    while (p[len] != '\0')
        len++;
        
    res = romanCharToInt(p[len-1]);
    for (i = len-1; i > 0; i--) {
        if (romanCharToInt(p[i]) > romanCharToInt(p[i-1])) {
            res  -= romanCharToInt(p[i-1]);
        } else {
            res += romanCharToInt(p[i-1]);
        }
    }
    
    return res;
}
