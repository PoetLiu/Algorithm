char findTheDifference(char* s, char* t) {
    int cnt[26] = {0}, i = 0;
    
    if (!s || !t)
        return 0;
    
    for (i = 0; t[i] != '\0'; i++)
        cnt[t[i]-'a']++;
    
    for (i = 0; s[i] != '\0'; i++)
        cnt[s[i]-'a']--;
    
    for (i = 0; i < sizeof(cnt); i++)
        if (cnt[i] == 1)
            return i+'a';
    return 0;
}
