int maxProfit(int* prices, int pricesSize) {
    int profit = 0, i = 0, j = 0, tmp = 0;
    
    if (!prices || pricesSize <=1)
        return 0;
        
    while(prices[i] > prices[i+1])
        i++;
    
    for (; i < pricesSize; i++) {
        for (j = i+1; j < pricesSize; j++) {
            if (prices[i] > prices[j])
                continue;
            tmp = prices[j]-prices[i];
            if (tmp > profit)
                profit  = tmp; 
        }
    }
ret:
    return profit;
}
