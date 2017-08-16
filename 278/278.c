// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

int binary_chop(int start, int end)
{
    int tmp = (end-start)/2 + start;
    if (tmp == start) 
        return isBadVersion(start) ? start : end;
    
    if (isBadVersion(tmp)) {
        if (isBadVersion(tmp - 1))
            return binary_chop(start, tmp - 1);
        else
            return tmp;
    } else{
        return binary_chop(tmp + 1, end);
    }
}

int firstBadVersion(int n) {
    return binary_chop(1, n);
}
