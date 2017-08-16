bool isPerfectSquare(int num) {
    int high = num, low = 1;
    long long mid, sqmid;
    
    if (num <= 0)
        return false;
    
      while (low <= high) {
         mid    = (low+high) >> 1;
         sqmid  = mid*mid;
        if (sqmid == num) {
            return true;
        } else if (sqmid < num) {
            low     = mid+1;
        } else {
            high    = mid-1;
        }
    }
    
    return false;
}
