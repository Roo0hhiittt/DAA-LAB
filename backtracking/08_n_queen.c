// N-Queen (Backtracking) | O(N!) with O(1) safety checks, Space O(N)
#include <stdio.h>
#define N 6

int col[N];                 // col[r] = column of queen in row r
int usedCol[N];             // is column used?
int diag1[2 * N];           // r - c + N - 1  (\ diagonal)
int diag2[2 * N];           // r + c          (/ diagonal)
int count = 0;

void printBoard() {
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++)
            printf("%c ", col[r] == c ? 'Q' : '.');
        printf("\n");
    }
    printf("\n");
}

void solve(int r) {
    if (r == N) {           // all queens placed
        count++;
        if (count == 1) printBoard();   // print only the first solution
        return;
    }
    for (int c = 0; c < N; c++) {
        // O(1) safety check using the three arrays
        if (usedCol[c] || diag1[r - c + N - 1] || diag2[r + c]) continue;

        col[r] = c;                                   // place
        usedCol[c] = diag1[r - c + N - 1] = diag2[r + c] = 1;

        solve(r + 1);                                 // recurse

        usedCol[c] = diag1[r - c + N - 1] = diag2[r + c] = 0;   // backtrack
    }
}

int main() {
    solve(0);
    printf("Total solutions for N=%d: %d\n", N, count);
    return 0;
}
