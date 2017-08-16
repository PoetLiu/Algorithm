int countPrimes(int n) {
    int res = 1, j = 3, i = 2, tmp = 0;
    if (n <= 2)
        return 0;
    
    for (; j < n; j++) {
        tmp = j%10;
        if (j > 10 && (tmp != 1 && tmp != 3 && tmp != 7 && tmp != 9))
            continue;
        tmp = sqrt(j);
        for (i = 2; i <= tmp; i++) {
            if (j%i == 0)
                break;
        } 
        if (i > tmp)
            res++;
    }
    return res;
}
