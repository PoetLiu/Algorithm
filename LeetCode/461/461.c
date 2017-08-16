int hammingDistance(int x, int y) {
    int result = x ^ y, i = 0, cnt = 0;
    if (x == y)
        return 0;
    for (; i <= 31; i++) {
        if (result & (1 << i))
            cnt++;
    }
    return cnt;
}
