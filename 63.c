#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int n; // number of vertices

// DFS function (recursive)
void dfs(int v) {
    printf("%d ", v);
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1 && visited[i] == 0) {
            dfs(i);
        }
    }
}

int main() {
    int source;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // initialize visited array
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("Enter source vertex: ");
    scanf("%d", &source);

    printf("DFS Traversal: ");
    dfs(source);

    return 0;
}
