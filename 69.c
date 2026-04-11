#include <stdio.h>
#include <limits.h>

#define SIZE 105

int networkDelayTime(int** times, int timesSize, int* timesColSize, int n, int k) {
    int dist[SIZE];
    int visited[SIZE] = {0};

    // Initialize distances
    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
    }
    dist[k] = 0;

    // Dijkstra
    for (int i = 1; i <= n; i++) {
        int u = -1;

        for (int j = 1; j <= n; j++) {
            if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }

        if (u == -1 || dist[u] == INT_MAX) break;

        visited[u] = 1;

        // Relax edges
        for (int i = 0; i < timesSize; i++) {
            int src = times[i][0];
            int dest = times[i][1];
            int weight = times[i][2];

            if (src == u && dist[u] + weight < dist[dest]) {
                dist[dest] = dist[u] + weight;
            }
        }
    }

    // Find answer
    int maxTime = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX) return -1;
        if (dist[i] > maxTime) maxTime = dist[i];
    }

    return maxTime;
}
