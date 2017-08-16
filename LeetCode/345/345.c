static inline bool isVowel(char c) {
    switch (c)  {
        case 'a':
        case 'A':
        case 'e':
        case 'E':
        case 'i':
        case 'I':
        case 'o':
        case 'O':
        case 'u':
        case 'U':
            return true;
        default:
            return false;
    }
}

char* reverseVowels(char* s) {
    int len = strlen(s), start = 0, end = len-1, tmp = 0;
    
    for (; start < end; start++, end--) {
        while (isVowel(s[start]) != true && start <= end)
            start++;
        while (isVowel(s[end]) != true && start <= end)
            end--;
        if (start >= end)
            goto ret;
        tmp = s[start];
        s[start]    = s[end];
        s[end]      = tmp;
    }
ret:
    return s;
}
