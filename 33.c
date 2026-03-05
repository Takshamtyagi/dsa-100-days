#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push function
void push(char x){
    stack[++top] = x;
}

// Pop function
char pop(){
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

// Priority function
int priority(char x){
    if(x == '^')
        return 3;
    if(x == '*' || x == '/')
        return 2;
    if(x == '+' || x == '-')
        return 1;
    return 0;
}

int main(){
    char infix[100], postfix[100];
    int i = 0, j = 0;
    char x;

    printf("Enter Infix Expression: ");
    scanf("%s", infix);

    push('(');
    strcat(infix, ")");

    while(infix[i] != '\0'){
        if(isalnum(infix[i])){
            postfix[j++] = infix[i];
        }
        else if(infix[i] == '('){
            push(infix[i]);
        }
        else if(infix[i] == ')'){
            while((x = pop()) != '('){
                postfix[j++] = x;
            }
        }
        else{
            while(priority(stack[top]) >= priority(infix[i])){
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
        i++;
    }

    postfix[j] = '\0';

    printf("Postfix Expression: %s\n", postfix);

    return 0;
}
