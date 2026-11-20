// Sum of Subsets (Backtracking) | Time O(2^n), Space O(n)
#include <stdio.h>

int w[] = {5, 10, 12, 13, 15, 18};   // sorted ascending
int n = 6, target = 30;
int include[10];                      // include[i] = 1 if w[i] is chosen

// sum = current sum, i = current index, remaining = sum of w[i..n-1]
void solve(int i, int sum, int remaining) {
    if (sum == target) {              // found a subset
        printf("{ ");
        for (int k = 0; k < n; k++)
            if (include[k]) printf("%d ", w[k]);
        printf("}\n");
        return;
    }
    // prune: no items left, overshoot, or not enough left to reach target
    if (i == n || sum > target || sum + remaining < target) return;

    include[i] = 1;                                   // choice 1: take w[i]
    solve(i + 1, sum + w[i], remaining - w[i]);

    include[i] = 0;                                   // choice 2: skip w[i]
    solve(i + 1, sum, remaining - w[i]);
}

int main() {
    int total = 0;
    for (int i = 0; i < n; i++) total += w[i];
    printf("Subsets with sum %d:\n", target);
    solve(0, 0, total);
    return 0;
}
