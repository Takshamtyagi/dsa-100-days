#include <stdio.h>
#define INFINITY 9999
#define MAX 10

// Dijkstra's algorithm: computes shortest distances from start vertex
void Dijkstra(int Graph[MAX][MAX], int n, int startnode) {
    int cost[MAX][MAX], distance[MAX], pred[MAX];
    int visited[MAX] = {0}, count = 0, mindistance, nextnode, i, j;

    // Step 1: Create cost matrix (0 -> INFINITY if no direct edge)
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (Graph[i][j] == 0)
                cost[i][j] = INFINITY;
            else
                cost[i][j] = Graph[i][j];

    // Step 2: Initialize distances from source, predecessors, and visited array
    for (i = 0; i < n; i++) {
        distance[i] = cost[startnode][i];
        pred[i] = startnode;
        visited[i] = 0;
    }
    distance[startnode] = 0;  // Distance to self is 0
    visited[startnode] = 1;
    count = 1;  // One vertex visited

    // Step 3: Main loop - repeat until all vertices visited
    while (count < n - 1) {
        // Find unvisited vertex with minimum distance
        mindistance = INFINITY;
        for (i = 0; i < n; i++)
            if (distance[i] < mindistance && !visited[i]) {
                mindistance = distance[i];
                nextnode = i;
            }

        visited[nextnode] = 1;  // Mark as visited

        // Update distances to all unvisited neighbors
        for (i = 0; i < n; i++)
            if (!visited[i])
                if (mindistance + cost[nextnode][i] < distance[i]) {
                    distance[i] = mindistance + cost[nextnode][i];
                    pred[i] = nextnode;
                }
        count++;
    }

    // Step 4: Output shortest distances (excluding source)
    for (i = 0; i < n; i++)
        if (i != startnode) {
            printf("\nDistance from source %d to %d: %d", startnode, i, distance[i]);
        }
}

int main() {
    int Graph[MAX][MAX], i, j, n = 7, u = 0;  // Example: 7 vertices, source=0

    // Example weighted graph (symmetric for undirected; adjust for directed)
    // Row 0: edges to 2(1), 3(2)
    Graph[0][0] = 0; Graph[0][1] = 0; Graph[0][2] = 1; Graph[0][3] = 2; Graph[0][4] = 0; Graph[0][5] = 0; Graph[0][6] = 0;
    Graph[1][0] = 0; Graph[1][1] = 0; Graph[1][2] = 2; Graph[1][3] = 0; Graph[1][4] = 0; Graph[1][5] = 3; Graph[1][6] = 0;
    Graph[2][0] = 1; Graph[2][1] = 2; Graph[2][2] = 0; Graph[2][3] = 1; Graph[2][4] = 3; Graph[2][5] = 0; Graph[2][6] = 0;
    Graph[3][0] = 2; Graph[3][1] = 0; Graph[3][2] = 1; Graph[3][3] = 0; Graph[3][4] = 0; Graph[3][5] = 0; Graph[3][6] = 1;
    Graph[4][0] = 0; Graph[4][1] = 0; Graph[4][2] = 3; Graph[4][3] = 0; Graph[4][4] = 0; Graph[4][5] = 2; Graph[4][6] = 0;
    Graph[5][0] = 0; Graph[5][1] = 3; Graph[5][2] = 0; Graph[5][3] = 0; Graph[5][4] = 2; Graph[5][5] = 0; Graph[5][6] = 1;
    Graph[6][0] = 0; Graph[6][1] = 0; Graph[6][2] = 0; Graph[6][3] = 1; Graph[6][4] = 0; Graph[6][5] = 1; Graph[6][6] = 0;

    Dijkstra(Graph, n, u);
    return 0;
}
