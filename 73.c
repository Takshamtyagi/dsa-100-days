#include <stdio.h>
#include <stdlib.h>

int find(int *parent, int x) {
    if (parent[x] != x) {
        parent[x] = find(parent, parent[x]);  // path compression
    }
    return parent[x];
}

int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    // Each node is labelled from 1 to n; so we need (edgesSize + 1) parents
    int n = edgesSize + 1;
    int *parent = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        int pu = find(parent, u);
        int pv = find(parent, v);

        if (pu == pv) {
            // This edge forms a cycle; it’s redundant
            *returnSize = 2;
            int *res = (int *)malloc(2 * sizeof(int));
            res[0] = u;
            res[1] = v;
            free(parent);
            return res;
        }

        // Union: attach one component to the other
        parent[pu] = pv;
    }

    *returnSize = 0;
    free(parent);
    return NULL;  // should never reach here per constraints
}

// Example usage (for testing)
int main() {
    int edgesSize = 3;
    int edgesColSize = 2;
    int **edges = (int **)malloc(edgesSize * sizeof(int *));
    for (int i = 0; i < edgesSize; i++) {
        edges[i] = (int *)malloc(2 * sizeof(int));
    }

    edges[0][0] = 1; edges[0][1] = 2;
    edges[1][0] = 1; edges[1][1] = 3;
    edges[2][0] = 2; edges[2][1] = 3;

    int returnSize;
    int *ans = findRedundantConnection(edges, edgesSize, &edgesColSize, &returnSize);

    if (ans) {
        printf("%d %d\n", ans[0], ans[1]);
        free(ans);
    }

    // Free edges
    for (int i = 0; i < edgesSize; i++) {
        free(edges[i]);
    }
    free(edges);

    return 0;
}
