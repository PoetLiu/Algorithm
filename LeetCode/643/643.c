double findMaxAverage(int* nums, int numsSize, int k) {
    double res = 0, avg = 0.0f;
    int i, j, sum = 0;
    
    for (i = 0; i + k <= numsSize; i++) {
        if (i == 0) {
            for (j = 0; j < k; j++) {
                sum += nums[i+j];
            }
            if (j != k)
                goto ret;
            res = (double)sum/k;
        } else {
            sum += nums[i+k-1]-nums[i-1];
        }
        avg = (double)sum/k;
        res = avg > res ? avg : res;
    }
ret:
    return res;
}
