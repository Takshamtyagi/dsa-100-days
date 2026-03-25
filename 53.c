#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 1000
#define MAX_HD 2000   // max horizontal distance (from min to max)

// Tree node
struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int val) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Queue node for level-order building
struct QueueNode {
    struct Node* node;
    int hd;  // horizontal distance from root
};

struct Queue {
    int front, rear;
    struct QueueNode data[MAX_HD];
};

void initQueue(struct Queue* q) {
    q->front = q->rear = 0;
}

int isEmpty(struct Queue* q) {
    return q->front == q->rear;
}

void enqueue(struct Queue* q, struct Node* node, int hd) {
    q->data[q->rear].node = node;
    q->data[q->rear].hd = hd;
    q->rear++;
}

struct QueueNode dequeue(struct Queue* q) {
    return q->data[q->front++];
}

// Build tree from level-order array (with -1 for NULL)
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Queue q;
    initQueue(&q);

    struct Node* root = newNode(arr[0]);
    enqueue(&q, root, 0);

    int i = 1;
    while (!isEmpty(&q) && i < n) {
        struct QueueNode curr = dequeue(&q);

        // left child
        if (i < n && arr[i] != -1) {
            curr.node->left = newNode(arr[i]);
            enqueue(&q, curr.node->left, curr.hd - 1);
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr.node->right = newNode(arr[i]);
            enqueue(&q, curr.node->right, curr.hd + 1);
        }
        i++;
    }

    return root;
}

// Print vertical order (BFS with horizontal distance)
void printVerticalOrder(struct Node* root) {
    if (!root) return;

    struct Queue q;
    initStation(&q);  // already defined above

    // We'll store each column in an array of lists
    int vertical[MAX_HD][MAX_NODES];   // [hd][0..cnt-1]
    int cnt[MAX_HD] = {0};             // count per column

    int offset = 1000;  // so hd can be negative; index = hd + offset
    int min_hd = 0, max_hd = 0;

    enqueue(&q, root, 0);

    while (!isEmpty(&q)) {
        struct QueueNode curr = dequeue(&q);
        int hd = curr.hd;

        int idx = hd + offset;
        vertical[idx][cnt[idx]] = curr.node->data;
        cnt[idx]++;

        min_hd = (hd < min_hd) ? hd : min_hd;
        max_hd = (hd > max_hd) ? hd : max_hd;

        if (curr.node->left)
            enqueue(&q, curr.node->left, hd - 1);
        if (curr.node->right)
            enqueue(&q, curr.node->right, hd + 1);
    }

    // Output from leftmost to rightmost vertical
    for (int hd = min_hd; hd <= max_hd; hd++) {
        int idx = hd + offset;
        for (int j = 0; j < cnt[idx]; j++) {
            printf("%d ", vertical[idx][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[MAX_NODES];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);
    printVerticalOrder(root);

    return 0;
}
