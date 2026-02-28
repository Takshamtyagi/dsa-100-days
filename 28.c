#include <stdio.h>
#include <stdlib.h>

// Structure of Node
struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Function to insert node at end
void insertEnd(int value) {

    // Create new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    // If list is empty
    if (head == NULL) {
        head = newNode;
        newNode->next = head;   // Point to itself
    }
    else {
        struct Node* temp = head;

        // Traverse to last node
        while (temp->next != head) {
            temp = temp->next;
        }

        temp->next = newNode;   // Last node points to new node
        newNode->next = head;   // New node points to head
    }
}

// Function to display circular linked list
void display() {

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;

    printf("Circular Linked List: ");

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    while (temp != head);

    printf("(back to head)\n");
}

int main() {

    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    insertEnd(40);

    display();

    return 0;
}