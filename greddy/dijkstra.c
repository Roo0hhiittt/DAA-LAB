#include <stdio.h>

#define V 5
#define INF 99999

int main()
{
    int graph[V][V] =
    {
        {0, 10, 0, 5, 0},
        {0, 0, 1, 2, 0},
        {0, 0, 0, 0, 4},
        {0, 3, 9, 0, 2},
        {7, 0, 6, 0, 0}
    };

    int distance[V];
    int visited[V];

    int source = 0;

    // Initialize
    for (int i = 0; i < V; i++)
    {
        distance[i] = INF;
        visited[i] = 0;
    }

    distance[source] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int min = INF;
        int u = -1;

        // Find nearest unvisited vertex
        for (int i = 0; i < V; i++)
        {
            if (visited[i] == 0 && distance[i] < min)
            {
                min = distance[i];
                u = i;
            }
        }

        if (u == -1)
            break;

        visited[u] = 1;

        // Update neighbours
        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] != 0 &&
                visited[v] == 0 &&
                distance[u] + graph[u][v] < distance[v])
            {
                distance[v] =
                    distance[u] + graph[u][v];
            }
        }
    }

    printf("Vertex\tDistance\n");

    for (int i = 0; i < V; i++)
    {
        printf("%d\t%d\n", i, distance[i]);
    }

    return 0;
}