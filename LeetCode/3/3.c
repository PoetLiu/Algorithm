int lengthOfLongestSubstring(char* s) {
    uint16_t map[127] = {0};
    int i, len = strlen(s), res = 0, j = 0;
    
    for (i = 0; i < len; i++) {
        if (map[s[i]] != 0) {
            j   = (j > map[s[i]]) ? j : (map[s[i]]);
        }
        map[s[i]]   = i+1;
        res = (res > i-j+1) ? res : (i-j+1);
    }
    return res;
}
