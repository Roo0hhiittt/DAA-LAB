// Optimal Binary Search Tree | Time O(n^3), Space O(n^2)
// Given search frequencies of sorted keys, find minimum search cost.
#include <stdio.h>
#include <limits.h>

int main() {
    int keys[] = {0, 10, 20, 30, 40};   // index 0 unused
    int freq[] = {0, 34, 8, 50, 20};    // frequency of each key
    int n = 4;

    int cost[20][20] = {0};   // cost[i][j] = min cost of BST for keys i..j
    int sum[20] = {0};        // prefix sums of freq

    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + freq[i];

    for (int i = 1; i <= n; i++) cost[i][i] = freq[i];

    for (int len = 2; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;
            cost[i][j] = INT_MAX;
            int total = sum[j] - sum[i - 1];
            for (int r = i; r <= j; r++) {      // try each key as root
                int c = cost[i][r - 1] + cost[r + 1][j] + total;
                if (c < cost[i][j]) cost[i][j] = c;
            }
        }
    }
    printf("Minimum cost of Optimal BST = %d\n", cost[1][n]);
    return 0;
}
