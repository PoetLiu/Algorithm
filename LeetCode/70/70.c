int climbStairs(int n) {
    static double S = sqrt(5.0);
    if (n <= 3)
        return n;
    return 1.0/S*(pow((1.0+S)/2.0, n+1) - pow((1.0-S)/2.0, n+1));
}
