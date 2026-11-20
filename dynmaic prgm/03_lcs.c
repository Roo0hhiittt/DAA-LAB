// Longest Common Subsequence | Time O(mn), Space O(mn)
#include <stdio.h>
#include <string.h>

int max(int a, int b) { return a > b ? a : b; }

int main() {
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
    int m = strlen(X), n = strlen(Y);
    int L[20][20];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
    printf("LCS length = %d\n", L[m][n]);

    // Build the LCS string by walking back through the table
    char lcs[20];
    int idx = L[m][n];
    lcs[idx] = '\0';
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs[--idx] = X[i - 1];
            i--; j--;
        } else if (L[i - 1][j] > L[i][j - 1])
            i--;
        else
            j--;
    }
    printf("LCS = %s\n", lcs);
    return 0;
}
