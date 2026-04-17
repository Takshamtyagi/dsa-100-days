#include <stdio.h>
#include <stdbool.h>

#define MAXN 1005

bool visited[MAXN];
int adj[MAXN][MAXN];
int n, m;

void dfs(int u) {
    visited[u] = true;
    for (int v = 0; v < n; v++) {
        if (adj[u][v] && !visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    
    // Initialize adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
        visited[i] = false;
    }
    
    // Read edges (undirected)
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    
    int components = 0;
    
    // Count connected components
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
            components++;
        }
    }
    
    printf("%d\n", components);
    return 0;
}
