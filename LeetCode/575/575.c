int cmpFunc(int *a, int *b)
{
    return *a-*b;
}

int distributeCandies(int* candies, int candiesSize) {
    int diff_num = 1, cmp = 0, i;
    
    qsort(candies, candiesSize, sizeof(int), cmpFunc);
    for (i = 1, cmp = candies[0]; i < candiesSize; i++) {
        if (cmp != candies[i]) {
            diff_num++;
            cmp = candies[i];
        }
    }
    return diff_num > (candiesSize/2) ? (candiesSize/2) : diff_num;
}
