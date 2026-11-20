// Matrix Chain Multiplication | Time O(n^3), Space O(n^2)
#include <stdio.h>
#include <limits.h>

// Matrix i has size p[i-1] x p[i]
void printParen(int s[][10], int i, int j) {
    if (i == j) { printf("A%d", i); return; }
    printf("(");
    printParen(s, i, s[i][j]);
    printParen(s, s[i][j] + 1, j);
    printf(")");
}

int main() {
    int p[] = {10, 30, 5, 60};
    int n = 3;                    // number of matrices
    int m[10][10] = {0};          // m[i][j] = min cost to multiply Ai..Aj
    int s[10][10] = {0};          // s[i][j] = best split point

    for (int len = 2; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int cost = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (cost < m[i][j]) {
                    m[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }
    printf("Minimum multiplications = %d\n", m[1][n]);
    printf("Best order: ");
    printParen(s, 1, n);
    printf("\n");
    return 0;
}
