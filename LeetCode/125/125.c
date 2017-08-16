bool isAlphaNumeric(char c) 
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

bool isAlphaNumericSame(char c1, char c2)
{
    if (c1 == c2)
        return true;
    if ((c1 >= '0' && c1 <= '9') || (c2 >= '0' && c2 <= '9'))
        return false;
    return (c1-'a') == (c2-'A') || (c1-'A') == (c2-'a');
}

bool isPalindrome(char* s) {
    int i = -1, j = 0, len = 0;
    
    if (!s || s[0] == '\0')
        return true;
    
    while (s[len] != '\0') {
        if (isAlphaNumeric(s[len]))
            i=(i==-1?len:i), j = len;
        len++;
    }
    
    while (i < j) {
        if (!isAlphaNumeric(s[i])) {
            i++;
            continue;
        }
        if (!isAlphaNumeric(s[j])) {
            j--;
            continue;
        }
        if (!isAlphaNumericSame(s[i], s[j]))
            return false;
        else
            i++, j--;
    }

    return true;
}
