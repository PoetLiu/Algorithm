bool judgeSquareSum(int c) {
    int left = 0, right = (int)sqrt(c), cur;
    
    while (left <= right) {
        cur = left*left+right*right;
        if (cur > c)
            right--;
        else if (cur < c)
            left++;
        else
            return true;
    }
    return false;
}
