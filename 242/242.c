bool isAnagram(char* s, char* t) {
    int bitMaps[26] = {0}, bitMapt[26] = {0}, lens = strlen(s), lent = strlen(t), i = 0, j = 0;
    bool res = false;
    
    if (lens != lent)
        goto ret;

    while (1) {
        if (i != lens)
            bitMaps[s[i++]-'a']++;
        if (j != lent)
            bitMapt[t[j++]-'a']++;
        if (i == lens && j == lens)
            break;
    }
    res = memcmp(bitMaps, bitMapt, sizeof(bitMaps)) == 0 ? true : false;
ret:
    return res;
}
