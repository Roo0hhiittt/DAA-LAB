// 0/1 Knapsack - Dynamic Programming | Time O(nW), Space O(nW)
#include <stdio.h>

int max(int a, int b) { return a > b ? a : b; }

int main() {
    int wt[] = {1, 3, 4, 5};
    int val[] = {1, 4, 5, 7};
    int n = 4, W = 7;
    int dp[10][20];

    // dp[i][w] = best value using first i items with capacity w
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    printf("Maximum value = %d\n", dp[n][W]);

    // Find which items were picked
    printf("Items picked: ");
    int w = W;
    for (int i = n; i > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            printf("%d ", i);
            w -= wt[i - 1];
        }
    }
    printf("\n");
    return 0;
}
