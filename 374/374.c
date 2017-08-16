// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        return binary_chop(1, n);
    }
private:
    int binary_chop(int start, int end) {
        int tmp = start + (end-start)/2;
        if (start == end)
            return start;
        switch (guess(tmp)) {
            case 0:
                return tmp;
            case -1:
                return binary_chop(start, tmp-1);
            case 1:
                return binary_chop(tmp+1, end);
        }
        return start;
    }
};
