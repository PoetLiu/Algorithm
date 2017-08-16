int islandPerimeter(int** grid, int gridRowSize, int gridColSize) {
    int i = 0, j = 0, res = 0;
    if (!grid || !*grid)
        return 0;
        
    for (i = 0; i < gridRowSize; i++) {
        for (j = 0; j < gridColSize; j++) {
            if (grid[i][j] != 1)
                continue;
            if (!j || grid[i][j-1] != 1)
                res++;
            if (!i || grid[i-1][j] != 1)
                res++;
            if (j+1 == gridColSize || grid[i][j+1] !=1)
                res++;
            if (i+1 == gridRowSize || grid[i+1][j] != 1)
                res++;
        }
    } 
    return res;
}
