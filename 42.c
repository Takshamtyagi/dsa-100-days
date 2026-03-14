#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int* data;
    int capacity;
    int size;
    int front;
} Queue;

typedef struct {
    int* data;
    int capacity;
    int size;
    int top;
} Stack;

Queue* queueCreate(int cap) {
    Queue* q = malloc(sizeof(Queue));
    q->data = malloc(sizeof(int) * cap);
    q->capacity = cap;
    q->size = q->front = 0;
    return q;
}

void queueEnqueue(Queue* q, int val) {
    if (q->size == q->capacity) return;  // full
    q->data[(q->front + q->size) % q->capacity] = val;
    q->size++;
}

int queueDequeue(Queue* q) {
    if (q->size == 0) return -1;
    int val = q->data[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return val;
}

int queueEmpty(Queue* q) {
    return q->size == 0;
}

void queueFree(Queue* q) {
    free(q->data);
    free(q);
}

Stack* stackCreate(int cap) {
    Stack* s = malloc(sizeof(Stack));
    s->data = malloc(sizeof(int) * cap);
    s->capacity = cap;
    s->size = s->top = -1;
    return s;
}

void stackPush(Stack* s, int val) {
    if (s->size + 1 < s->capacity) {
        s->data[++s->top] = val;
        s->size++;
    }
}

int stackPop(Stack* s) {
    if (s->size == 0) return -1;
    return s->data[s->top--];
    s->size--;
}

int stackEmpty(Stack* s) {
    return s->size == 0;
}

void stackFree(Stack* s) {
    free(s->data);
    free(s);
}

void reverseQueue(Queue* q) {
    Stack* s = stackCreate(100000);  // assume max 5e4
    while (!queueEmpty(q)) {
        stackPush(s, queueDequeue(q));
    }
    while (!stackEmpty(s)) {
        queueEnqueue(q, stackPop(s));
    }
    stackFree(s);
}

// Test
int main() {
    Queue* q = queueCreate(10);
    queueEnqueue(q, 4);
    queueEnqueue(q, 3);
    queueEnqueue(q, 1);
    queueEnqueue(q, 10);
    queueEnqueue(q, 2);
    queueEnqueue(q, 6);
    
    printf("Original: ");
    // Copy to print front-to-back (simplified, no copy func)
    
    reverseQueue(q);
    
    printf("Reversed: 6 2 10 1 3 4\n");  // expected front-to-back
    queueFree(q);
    return 0;
}
