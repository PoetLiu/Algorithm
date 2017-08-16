bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    int i = 0, max = 0;
    
    for (i; i < flowerbedSize;) {
        if (flowerbed[i] == 0 && (i == 0 || flowerbed[i-1] == 0) && (flowerbed[i+1] == 0 || i == flowerbedSize-1)) {
            flowerbed[i]    = 1;
            max++;
            i   +=  2;
        } else {
            i++;
        }
    }
    return max >= n;
}
