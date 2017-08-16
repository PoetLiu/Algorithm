int longestPalindrome(char* s) {
    short bitMap[52] = {0}, len = strlen(s), i = 0;
    int ret = 0, idx = 0;
    
    while (i != len) {
        idx = (s[i] >= 'A' && s[i] <= 'Z' ? 26+s[i]-'A' : s[i]-'a');
        bitMap[idx]++;
        i++;
    }
    
    for (i = 0; i < 52; i++) {
        ret += (bitMap[i]/2)*2;
    }
    return ret == len ? ret : ret+1;
}
