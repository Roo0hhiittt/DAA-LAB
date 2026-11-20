// Travelling Salesman Problem (Held-Karp bitmask DP)
// Time O(n^2 * 2^n), Space O(n * 2^n)
#include <stdio.h>
#define INF 1000000
#define N 4

int main() {
    int dist[N][N] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };
    int FULL = (1 << N) - 1;
    // dp[mask][i] = min cost to visit cities in 'mask', ending at city i
    static int dp[1 << N][N];

    for (int m = 0; m <= FULL; m++)
        for (int i = 0; i < N; i++) dp[m][i] = INF;

    dp[1][0] = 0;   // start at city 0

    for (int mask = 1; mask <= FULL; mask++) {
        for (int last = 0; last < N; last++) {
            if (!(mask & (1 << last)) || dp[mask][last] == INF) continue;
            for (int next = 0; next < N; next++) {
                if (mask & (1 << next)) continue;      // already visited
                int newMask = mask | (1 << next);
                int cost = dp[mask][last] + dist[last][next];
                if (cost < dp[newMask][next]) dp[newMask][next] = cost;
            }
        }
    }

    int ans = INF;
    for (int i = 1; i < N; i++) {                      // return to city 0
        int cost = dp[FULL][i] + dist[i][0];
        if (cost < ans) ans = cost;
    }
    printf("Minimum tour cost = %d\n", ans);
    return 0;
}
