#include <stdio.h>

#define MAX 20

struct Edge
{
    int src;
    int dest;
    int weight;
};

// Find parent
int findParent(int parent[], int vertex)
{
    while (parent[vertex] != vertex)
    {
        vertex = parent[vertex];
    }

    return vertex;
}

int main()
{
    int V, E;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    struct Edge edges[MAX];

    printf("Enter source destination weight:\n");

    for (int i = 0; i < E; i++)
    {
        scanf("%d %d %d",
              &edges[i].src,
              &edges[i].dest,
              &edges[i].weight);
    }

    // Sort edges according to weight
    for (int i = 0; i < E - 1; i++)
    {
        for (int j = i + 1; j < E; j++)
        {
            if (edges[i].weight > edges[j].weight)
            {
                struct Edge temp = edges[i];
                edges[i] = edges[j];
                edges[j] = temp;
            }
        }
    }

    int parent[MAX];

    // Initially every vertex is its own parent
    for (int i = 0; i < V; i++)
    {
        parent[i] = i;
    }

    int count = 0;
    int totalCost = 0;

    printf("\nEdges in MST:\n");

    for (int i = 0; i < E && count < V - 1; i++)
    {
        int sourceParent =
            findParent(parent, edges[i].src);

        int destinationParent =
            findParent(parent, edges[i].dest);

        // If parents are different, no cycle
        if (sourceParent != destinationParent)
        {
            printf("%d - %d = %d\n",
                   edges[i].src,
                   edges[i].dest,
                   edges[i].weight);

            totalCost += edges[i].weight;

            // Join both sets
            parent[sourceParent] = destinationParent;

            count++;
        }
    }

    printf("Total MST Cost = %d\n", totalCost);

    return 0;
}