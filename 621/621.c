int bitCmpFunc(int *a, int *b)
{
    return (*b)-(*a);
}

int numMax(int a, int b)
{
    return a > b ? a : b;
}
int leastInterval(char* tasks, int tasksSize, int n) {
    int bitMap[26] = {0};
    int i, ret = 0;
    
    for (i = 0; i < tasksSize; i++) {
        bitMap[tasks[i]-'A']++;
    }
    qsort(bitMap, 26, sizeof(bitMap[0]), bitCmpFunc);
    i   = 0;
    while (i < 26 && bitMap[0] == bitMap[i])
        i++;
    return numMax(tasksSize, (bitMap[0]-1)*(n+1)+i);
}
