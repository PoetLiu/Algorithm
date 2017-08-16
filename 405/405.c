char _toHex(int num)
{
    return (num >= 10) ? ('a'+num-10) : ('0'+num);
}

char* toHex(int num) {
    unsigned int n = num;
    char hex[8+1] = {0};
    int i = 8-1;
    
    hex[i] = '0';
    while (n%16 || n/16) {
        hex[i--]  = _toHex(n%16);
        n   = n/16;
    }
    
    i   = 0; 
    while (hex[i] == 0)
        i++;
    return strdup(&hex[i]);
    
}
