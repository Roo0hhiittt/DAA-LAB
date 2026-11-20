// 0/1 Knapsack (Backtracking) | Time O(2^n), Space O(n)
#include <stdio.h>

int wt[] = {1, 3, 4, 5};
int val[] = {1, 4, 5, 7};
int n = 4, W = 7;

int best = 0;
int cur[10], bestSet[10];

void solve(int i, int weight, int value) {
    if (weight > W) return;                 // over capacity: backtrack
    if (value > best) {                     // better answer found
        best = value;
        for (int k = 0; k < n; k++) bestSet[k] = cur[k];
    }
    if (i == n) return;

    cur[i] = 1;                             // choice 1: take item i
    solve(i + 1, weight + wt[i], value + val[i]);

    cur[i] = 0;                             // choice 2: skip item i
    solve(i + 1, weight, value);
}

int main() {
    solve(0, 0, 0);
    printf("Maximum value = %d\n", best);
    printf("Items picked: ");
    for (int i = 0; i < n; i++)
        if (bestSet[i]) printf("%d ", i + 1);
    printf("\n");
    return 0;
}
