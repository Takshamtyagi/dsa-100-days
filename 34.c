#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* push(Node* top, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = top;
    return newNode;
}

Node* pop(Node* top, int* value) {
    if (top == NULL) return NULL;
    Node* temp = top;
    *value = temp->data;
    top = top->next;
    free(temp);
    return top;
}

int evaluatePostfix(char* exp) {
    Node* stack = NULL;
    int i = 0;

    while (exp[i] != '\0') {
        if (isspace(exp[i])) {
            i++;
            continue;
        }

        if (isdigit(exp[i])) {
            int num = 0;
            while (isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            stack = push(stack, num);
        } 
        else {
            int val1, val2;
            stack = pop(stack, &val1);
            stack = pop(stack, &val2);

            int result;
            switch (exp[i]) {
                case '+': result = val2 + val1; break;
                case '-': result = val2 - val1; break;
                case '*': result = val2 * val1; break;
                case '/': result = val2 / val1; break;
            }

            stack = push(stack, result);
            i++;
        }
    }

    int finalResult;
    stack = pop(stack, &finalResult);
    return finalResult;
}

int main() {
    char exp[100];

    printf("Enter postfix expression: ");
    fgets(exp, sizeof(exp), stdin);

    int result = evaluatePostfix(exp);
    printf("Result = %d\n", result);

    return 0;
}
