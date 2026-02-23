#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct Node* mergeLists(struct Node* l1, struct Node* l2) {
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;

    while (l1 != NULL && l2 != NULL) {
        if (l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    if (l1 != NULL)
        tail->next = l1;
    else
        tail->next = l2;

    return dummy.next;
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    struct Node* merged = NULL;

    int n1, n2, x;

    printf("Enter number of elements in first sorted list: ");
    scanf("%d", &n1);

    printf("Enter elements:\n");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &x);
        insertEnd(&list1, x);
    }

    printf("Enter number of elements in second sorted list: ");
    scanf("%d", &n2);

    printf("Enter elements:\n");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &x);
        insertEnd(&list2, x);
    }

    printf("\nList 1: ");
    display(list1);

    printf("List 2: ");
    display(list2);

    merged = mergeLists(list1, list2);

    printf("Merged List: ");
    display(merged);

    return 0;
}