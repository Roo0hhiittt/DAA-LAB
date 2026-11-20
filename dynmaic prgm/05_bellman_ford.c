// Bellman-Ford shortest path | Time O(VE), Space O(V)
#include <stdio.h>
#define INF 1000000

struct Edge { int u, v, w; };

int main() {
    int V = 5, E = 8;
    struct Edge edges[] = {
        {0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2},
        {1, 4, 2},  {3, 2, 5}, {3, 1, 1}, {4, 3, -3}
    };
    int src = 0;
    int dist[10];

    for (int i = 0; i < V; i++) dist[i] = INF;
    dist[src] = 0;

    // Relax every edge V-1 times
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].u, v = edges[j].v, w = edges[j].w;
            if (dist[u] != INF && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }

    // One more pass: if anything still improves, there is a negative cycle
    for (int j = 0; j < E; j++) {
        int u = edges[j].u, v = edges[j].v, w = edges[j].w;
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            printf("Graph has a negative weight cycle!\n");
            return 0;
        }
    }

    printf("Vertex  Distance from source %d\n", src);
    for (int i = 0; i < V; i++) printf("%d\t%d\n", i, dist[i]);
    return 0;
}
