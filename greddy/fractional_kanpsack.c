#include <stdio.h>

int main()
{
    int n = 3;

    float profit[] = {60, 100, 120};
    float weight[] = {10, 20, 30};

    float capacity = 50;
    float totalProfit = 0;

    // Sort according to profit/weight ratio
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            float ratio1 = profit[i] / weight[i];
            float ratio2 = profit[j] / weight[j];

            if (ratio1 < ratio2)
            {
                float temp;

                temp = profit[i];
                profit[i] = profit[j];
                profit[j] = temp;

                temp = weight[i];
                weight[i] = weight[j];
                weight[j] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (capacity >= weight[i])
        {
            capacity = capacity - weight[i];
            totalProfit = totalProfit + profit[i];
        }
        else
        {
            totalProfit = totalProfit +
                          (profit[i] / weight[i]) * capacity;

            break;
        }
    }

    printf("Maximum profit = %.2f", totalProfit);

    return 0;
}