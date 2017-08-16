/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fizzBuzz(int n, int* returnSize) {
    static char *str[] = {"Fizz", "Buzz", "FizzBuzz"};
    char **res = NULL, *tmp = NULL;
    char buf[16];
    int i = 0, j = 0, k = 0;
    
    if (n <= 0 || !returnSize)
        return NULL;
        
    res = malloc(n * sizeof *res);
    if (!res) 
        return NULL;
    
    for (i = 1; i <= n; i++) {
        j   = !(i%3);
        k   = !(i%5);
        if (j && k) {
            res[i-1]    = strdup(str[2]);
        } else if (k) {
            res[i-1]    = strdup(str[1]);
        } else if (j) {
            res[i-1]    = strdup(str[0]);
        } else {
            snprintf(buf, sizeof(buf), "%d", i);
            res[i-1]    = strdup(buf);
        }
    }
    *returnSize = n;
    return res;
}
