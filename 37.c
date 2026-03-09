#include <stdio.h>
#define MAX 100

int pq[MAX];
int size = 0;

void insert(int value) {
    if (size == MAX) {
        printf("Queue Overflow\n");
        return;
    }

    int i = size - 1;

    while (i >= 0 && pq[i] > value) {
        pq[i + 1] = pq[i];
        i--;
    }

    pq[i + 1] = value;
    size++;
}

int delete() {
    if (size == 0) {
        printf("Queue Underflow\n");
        return -1;
    }

    int value = pq[0];

    for (int i = 1; i < size; i++) {
        pq[i - 1] = pq[i];
    }

    size--;
    return value;
}

int peek() {
    if (size == 0) {
        printf("Queue Empty\n");
        return -1;
    }

    return pq[0];
}

void display() {
    for (int i = 0; i < size; i++) {
        printf("%d ", pq[i]);
    }
    printf("\n");
}

int main() {
    insert(30);
    insert(10);
    insert(50);
    insert(20);

    display();

    printf("Highest Priority Removed: %d\n", delete());
    display();

    printf("Highest Priority Element: %d\n", peek());

    return 0;
}
