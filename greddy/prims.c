#include <stdio.h>

#define V 5
#define INF 99999

int main()
{
    int graph[V][V] =
    {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    int selected[V] = {0};

    int edges = 0;
    int totalCost = 0;

    // Start from vertex 0
    selected[0] = 1;

    printf("Edge\tWeight\n");

    while (edges < V - 1)
    {
        int min = INF;
        int x = 0;
        int y = 0;

        // Check all selected vertices
        for (int i = 0; i < V; i++)
        {
            if (selected[i] == 1)
            {
                // Find connection to unselected vertex
                for (int j = 0; j < V; j++)
                {
                    if (selected[j] == 0 &&
                        graph[i][j] != 0)
                    {
                        if (graph[i][j] < min)
                        {
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        printf("%d - %d\t%d\n", x, y, min);

        totalCost = totalCost + min;

        selected[y] = 1;

        edges++;
    }

    printf("Total MST Cost = %d\n", totalCost);

    return 0;
}