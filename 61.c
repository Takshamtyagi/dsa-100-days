#include <stdbool.h>
#include <string.h>

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    bool* visited = (bool*)calloc(roomsSize, sizeof(bool));
    int* stack = (int*)malloc(roomsSize * sizeof(int));
    int top = 0;
    int count = 0;

    // Start from room 0
    stack[top++] = 0;
    visited[0] = true;
    count++;

    while (top > 0) {
        int curr = stack[--top];

        // For each key in rooms[curr]
        for (int i = 0; i < roomsColSize[curr]; i++) {
            int next = rooms[curr][i];
            if (!visited[next]) {
                visited[next] = true;
                stack[top++] = next;
                count++;
            }
        }
    }

    free(stack);
    free(visited);

    return count == roomsSize;
}
