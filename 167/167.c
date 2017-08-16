/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int *res = calloc(1, sizeof(int)*2);
    int i, j, tmp = 0;
    
    if (!numbers || numbersSize < 1 || *returnSize)
        goto ret;
    
    for (i = 0; i < numbersSize; i++) {
        tmp = target - numbers[i];
        for (j = i+1; j < numbersSize; j++) {
            if (tmp == numbers[j]) {
                res[0]  = i+1;
                res[1]  = j+1;
                goto ret;
            } else if (tmp < numbers[j]) {
                break;
            }
        }
    }
    
ret:
    *returnSize = 2;
    return res;
}
