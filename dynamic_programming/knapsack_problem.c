#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapSack(int W, int wt[], int val[], int n) {
    if (n == 0 || W == 0) {
        return 0;
    }

    if (wt[n - 1] > W) { // if item is more than capacity, this item cannot be in the bag
        return knapSack(W, wt, val, n - 1);
    } else {

        // first is when item is included, second is when item is not included
        return max(
            val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1), // included 
            knapSack(W, wt, val, n - 1) // not included
        );
    }
}

int main() {
    int profit[] = {60, 100, 120};
    int weight[] = {10, 20, 30};

    int W = 50;
    int n = sizeof(profit) / sizeof(profit[0]);
    printf("%d", knapSack(W, weight, profit, n));

    return 0;
}