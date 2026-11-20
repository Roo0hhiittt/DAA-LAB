#include <stdio.h>

#define N 4

int knows[N][N] =
{
    {0, 1, 1, 1},
    {0, 0, 1, 1},
    {0, 0, 0, 0},
    {0, 1, 1, 0}
};

int findCelebrity()
{
    int candidate = 0;

    // Find possible celebrity
    for (int i = 1; i < N; i++)
    {
        if (knows[candidate][i] == 1)
        {
            candidate = i;
        }
    }

    // Verify candidate
    for (int i = 0; i < N; i++)
    {
        if (i != candidate)
        {
            if (knows[candidate][i] == 1 ||
                knows[i][candidate] == 0)
            {
                return -1;
            }
        }
    }

    return candidate;
}

int main()
{
    int result = findCelebrity();

    if (result == -1)
        printf("No celebrity found");
    else
        printf("Celebrity is person %d", result);

    return 0;
}