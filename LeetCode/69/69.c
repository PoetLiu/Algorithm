int mySqrt(int x) {
    int start = 0, end = x/2, mid, ret = 0, sqmid;
    if (x <= 1)
        return x;
    
    end =  end > 46340 ? 46340 : end;
    while (start <= end) {
        mid = (start+end)/2;
        sqmid   = mid*mid;
        if (sqmid == x) {
            return mid;
        } else if (sqmid > x) {
            end = mid-1;
        } else {
            start = mid+1;
            if (x-sqmid < x-ret*ret)
                ret = mid;
        }
    }
ret:
    return ret;
}
