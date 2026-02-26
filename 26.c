#include <stdio.h>
#include <stdlib.h>

// Structure of Doubly Linked List Node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;   // Global head pointer

// Insert at Beginning
void insertBegin(int value) {

    // Step 1: Create new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    // Step 2: Assign data
    newNode->data = value;

    // Step 3: New node's prev will be NULL
    newNode->prev = NULL;

    // Step 4: New node's next will point to current head
    newNode->next = head;

    // Step 5: If list is not empty, update old head's prev
    if (head != NULL) {
        head->prev = newNode;
    }

    // Step 6: Move head to new node
    head = newNode;
}

// Insert at End
void insertEnd(int value) {

    // Step 1: Create new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    // Step 2: If list is empty
    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    // Step 3: Traverse to last node
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Step 4: Attach new node
    temp->next = newNode;
    newNode->prev = temp;
}

// Forward Traversal
void displayForward() {

    struct Node* temp = head;

    printf("Forward: ");

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

// Backward Traversal
void displayBackward() {

    struct Node* temp = head;

    // Go to last node
    while (temp != NULL && temp->next != NULL) {
        temp = temp->next;
    }

    printf("Backward: ");

    // Traverse backward using prev pointer
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }

    printf("\n");
}

// Main Function
int main() {

    insertBegin(10);
    insertBegin(5);
    insertEnd(20);
    insertEnd(30);

    displayForward();
    displayBackward();

    return 0;
}