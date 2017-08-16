bool detectCapitalUse(char* word) {
    bool firstCap = false;
    int i = 0, cnt = 0;
    
    while (word[i] != '\0') {
        if (word[i] >= 'A' && word[i] <= 'Z') {
            cnt++;
            firstCap = (i==0) ? true : firstCap;
        }
        i++;
    }
    
    if (cnt == i || cnt == 0 || firstCap && cnt == 1) {
        return true;
    }
    return false;
}
