#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

// Enqueue
void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (front == NULL) {
        front = rear = newNode;
        rear->next = front;
    } else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }

    printf("Inserted: %d\n", value);
}

// Dequeue
void dequeue() {
    if (front == NULL) {
        printf("Queue is Empty\n");
        return;
    }

    struct Node* temp = front;

    if (front == rear) {
        front = rear = NULL;
    } else {
        front = front->next;
        rear->next = front;
    }

    printf("Deleted: %d\n", temp->data);
    free(temp);
}

// Display
void display() {
    if (front == NULL) {
        printf("Queue is Empty\n");
        return;
    }

    struct Node* temp = front;
    printf("Queue: ");

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);

    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
