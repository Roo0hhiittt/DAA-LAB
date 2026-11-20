#include <stdio.h>

#define MAX 100

int main()
{
    int freq[MAX];
    int n;

    printf("Enter number of characters: ");
    scanf("%d", &n);

    printf("Enter frequencies:\n");

    for (int i = 0; i < n; i++)
        scanf("%d", &freq[i]);

    int totalCost = 0;

    while (n > 1)
    {
        // Sort frequencies
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (freq[i] > freq[j])
                {
                    int temp = freq[i];
                    freq[i] = freq[j];
                    freq[j] = temp;
                }
            }
        }

        // Combine two smallest frequencies
        int sum = freq[0] + freq[1];

        totalCost += sum;

        printf("Combine %d and %d = %d\n",
               freq[0], freq[1], sum);

        freq[1] = sum;

        // Remove first element
        for (int i = 0; i < n - 1; i++)
            freq[i] = freq[i + 1];

        n--;
    }

    printf("Total cost = %d", totalCost);

    return 0;
}