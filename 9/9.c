int countDigits(int n)
{
    int i = 0;
    while (n) {
        i++;
        n   /= 10;
    }
    return i;
}

int MyPow10(int n)
{
    int res = 1;
    while (n--)
        res *= 10;
    return res;
}

bool isPalindrome(int x) {
    int i = 0, cnt = 0, tmp = x, res = 0;
    
    if (x < 0)
        return false;
        
    for (i = 0, cnt = countDigits(tmp); i < cnt; i++, tmp/=10) {
        if (cnt%2 && i == cnt/2)
            continue;
        if (i < cnt/2)
            res += tmp%10;
        else 
            res -= tmp%10;
    }
    if (res)
        return false;
        
    cnt = countDigits(x);
    for (i = 0, tmp = x; cnt > 1; i++, cnt = countDigits(tmp)) {
        if (tmp%10 != tmp/MyPow10(cnt-1))
            return false;
        tmp = tmp%MyPow10(cnt-1);
        tmp /= 10;
        while (tmp && (tmp%10 == 0))
            tmp /= 10;
    }
    return true;
}
