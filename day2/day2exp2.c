#include <stdio.h>
int maxProfit(int* prices, int pricesSize) {
    int minPrice = prices[0];
    int maxProfit = 0;
    for (int i = 1; i < pricesSize; i++) {
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        } else if (prices[i] - minPrice > maxProfit) {
            maxProfit = prices[i] - minPrice;
        }
    }
    return maxProfit;
}
int main() {
    int prices1[] = {7, 1, 5, 3, 6, 4};
    int size1 = sizeof(prices1) / sizeof(prices1[0]);
    int prices2[] = {7, 6, 4, 3, 1};
    int size2 = sizeof(prices2) / sizeof(prices2[0]);
    printf("Max Profit 1: %d\n", maxProfit(prices1, size1));
    printf("Max Profit 2): %d\n", maxProfit(prices2, size2));
    return 0;
}
