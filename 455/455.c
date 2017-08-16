int cmpFunc(int *a, int *b)
{
    return (*a)-(*b);
}

int findContentChildren(int* g, int gSize, int* s, int sSize) {
    int i, j, res = 0;
    
    qsort(g, gSize, sizeof(int), cmpFunc);
    qsort(s, sSize, sizeof(int), cmpFunc);
    
    for (i = 0, j = 0; i < gSize && j < sSize; i++, j++) {
        while (g[i] > s[j] && j < sSize)
            j++;
        if (j == sSize)
            break;
        else
            res++;
    }
    return res;
}
