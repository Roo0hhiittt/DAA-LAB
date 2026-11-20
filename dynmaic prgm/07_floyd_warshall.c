// Floyd-Warshall all-pairs shortest path | Time O(V^3), Space O(V^2)
#include <stdio.h>
#define V 4
#define INF 99999

int main() {
    int d[V][V] = {
        {0,   3,   INF, 7},
        {8,   0,   2,   INF},
        {5,   INF, 0,   1},
        {2,   INF, INF, 0}
    };

    // k = the intermediate vertex we are allowed to pass through
    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                if (d[i][k] + d[k][j] < d[i][j])
                    d[i][j] = d[i][k] + d[k][j];

    printf("Shortest distance matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (d[i][j] == INF) printf("%5s", "INF");
            else printf("%5d", d[i][j]);
        }
        printf("\n");
    }
    return 0;
}
