bool canConstruct(char* ransomNote, char* magazine) {
    int cnt[26] = {0}, i = 0;
    if (!magazine || !ransomNote || (ransomNote[0] != '\0' && magazine[0] == '\0'))
        return false;
    if (ransomNote[0] == '\0')
        return true;
    
    for (i = 0; magazine[i] != '\0'; i++) {
        cnt[magazine[i]-'a']++;
    }
    
    for (i = 0; ransomNote[i] != '\0'; i++) {
        if (cnt[ransomNote[i]-'a'] == 0)
            return false;
        cnt[ransomNote[i]-'a']--;
    }
    return true;
}
