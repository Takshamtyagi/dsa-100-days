#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Adjacency List Node
typedef struct Node {
    int dest;
    struct Node* next;
} Node;

// Graph Structure
typedef struct Graph {
    int numVertices;
    Node** adjLists;
    int* visited; // 0: unvisited, 1: visiting, 2: visited
} Graph;

// Create a new node
Node* createNode(int d) {
    Node* newNode = malloc(sizeof(Node));
    newNode->dest = d;
    newNode->next = NULL;
    return newNode;
}

// Create a graph
Graph* createGraph(int vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(Node*));
    graph->visited = malloc(vertices * sizeof(int));
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

// Add edge
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

// DFS Helper
bool dfs(Graph* graph, int v, int* stack, int* top) {
    graph->visited[v] = 1; // Mark as "Visiting"

    Node* temp = graph->adjLists[v];
    while (temp != NULL) {
        int neighbor = temp->dest;
        if (graph->visited[neighbor] == 1) return false; // Cycle detected
        if (graph->visited[neighbor] == 0) {
            if (!dfs(graph, neighbor, stack, top)) return false;
        }
        temp = temp->next;
    }

    graph->visited[v] = 2; // Mark as "Visited"
    stack[(*top)--] = v;    // Add to stack in reverse order
    return true;
}

void topologicalSort(Graph* graph) {
    int* stack = malloc(graph->numVertices * sizeof(int));
    int top = graph->numVertices - 1;
    bool possible = true;

    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->visited[i] == 0) {
            if (!dfs(graph, i, stack, &top)) {
                possible = false;
                break;
            }
        }
    }

    if (possible) {
        printf("Topological Order: ");
        for (int i = top + 1; i < graph->numVertices; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    } else {
        printf("Error: Graph contains a cycle. Topological sort impossible.\n");
    }

    free(stack);
}

int main() {
    int vertices = 6;
    Graph* graph = createGraph(vertices);
    
    // Example: 5 -> 2, 5 -> 0, 4 -> 0, 4 -> 1, 2 -> 3, 3 -> 1
    addEdge(graph, 5, 2);
    addEdge(graph, 5, 0);
    addEdge(graph, 4, 0);
    addEdge(graph, 4, 1);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1);

    topologicalSort(graph);

    return 0;
}
