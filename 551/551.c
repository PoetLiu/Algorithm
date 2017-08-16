#define MAX_VALID_CON_NUM_L 2
#define MAX_VALID_NUM_A     1
bool checkRecord(char* s) {
    bool ret = false;
    int lNum = 0, aNum = 0, i;
    
    if (!s)
        goto f;
    
    for (i = 0; s[i] != '\0'; i++) {
        switch (s[i]) {
            case 'A':
                aNum++;
                if (aNum > MAX_VALID_NUM_A) {
                    goto f;
                }
                lNum    = 0;
                break;
            case 'L':
                lNum++;
                if (lNum > MAX_VALID_CON_NUM_L) {
                    goto f;
                }
                break;
            default:
                lNum    = 0;
                break;
        }
            
    }
t:
    return true;
f:
    return false;

}
