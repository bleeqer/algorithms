#include <stdio.h>

int n = 5;
int p[5] = {3, 3, 2, 5, 1};
int w[5] = {10, 15, 10, 12, 8};
int W = 10;

int main() {
    int currentWeight;
    float totalValue;
    int i;
    int maxi;
    int used[10];

    for (i = 0; i < n; i++) {
        used[i] = 0;
    }

    currentWeight = W;

    while (currentWeight > 0) {
        maxi = -1;
        for (i = 0; i < n; i++) {
            if (used[i] == 0 && (maxi == -1 || (float) p[i] / w[i] > (float) p[maxi] / w[maxi])) {
                maxi = i;
            }
        }
        used[maxi] = 1;

        currentWeight -= w[maxi];
        totalValue += p[maxi];

        if (currentWeight >= 0) {
            printf("Added object %d (%d, %d) completely in the bag. Space left : %d.\n", maxi + 1, p[maxi], w[maxi], currentWeight);
        } else {
            printf("Added %d%% (%d, %d) of object %d in the bag.\n", (int) ((1 + (float) currentWeight / w[maxi]) * 100), p[maxi], w[maxi], maxi + 1);
            totalValue -= p[maxi];
            totalValue += (1 + (float) currentWeight / w[maxi] * p[maxi]);
        }
    }
    printf("Filled the bag with objects worth %.2f.\n", totalValue);
    return 0;
}