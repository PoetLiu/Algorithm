/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */



#define GET_ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))
int KeyBitsMap[] = {0, 0, 0};
char *KeyBorad[] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};

int keyBoradRowIdGet(char c) 
{
    int i, idx = 0, bitMask;
    
    c   = (c >= 'A' && c <= 'Z') ? c+32 : c;
    bitMask = 1 << (c-'a');
    for (i = 0; i < GET_ARRAY_SIZE(KeyBitsMap); i++) {
        if (bitMask & KeyBitsMap[i]) {
            return i;
        }
    }

    return -1;
}

void resAddItem(char ***res, int *cnt, char *item)
{
    (*cnt)++;
    *res = realloc(*res, sizeof(**res)*(*cnt));
    if (!*res)
        return;
    (*res)[(*cnt)-1]    = strdup(item);
    return;
    
}

char** findWords(char** words, int wordsSize, int* returnSize) {
    static int init = 1;
    int i, j, tmp, match = 1;
    char **res = NULL;
    
    if (init) {
        for (i = 0; i < GET_ARRAY_SIZE(KeyBitsMap); i++) {
            for (j = 0, tmp = 0; j < strlen(KeyBorad[i]); j++) {
                tmp |= 1 << (KeyBorad[i][j]-'a');
            }
            KeyBitsMap[i]   = tmp;
        }
        init    = 0;
    }
    
    for (i = 0; i < wordsSize; i++) {
        match = 1;
        tmp = keyBoradRowIdGet(words[i][0]);
        for (j = 1; j < strlen(words[i]); j++) {
            if (keyBoradRowIdGet(words[i][j]) != tmp) {
                match = 0;
                break;
            }
        }
        if (match) {
            resAddItem(&res, returnSize, words[i]);
        }
    }
    
    return res;
}
