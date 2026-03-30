#include <stdio.h>
#include <stdlib.h>

// Binary tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Hash map to store inorder index: value + OFFSET -> index
#define OFFSET 3000
#define MAX_MAP 6001
int map[MAX_MAP];

// Helper: recursively build tree from preorder & inorder ranges
struct TreeNode* buildFromPreIn(
    int* preorder, int* inorder,
    int preStart, int inStart, int inEnd
) {
    if (inStart > inEnd) {
        return NULL;
    }

    int rootVal = preorder[preStart];
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = rootVal;
    root->left = root->right = NULL;

    // index of root in inorder
    int idx = map[rootVal + OFFSET];
    int leftSubtreeSize = idx - inStart;

    root->left = buildFromPreIn(
        preorder, inorder,
        preStart + 1, inStart, idx - 1
    );

    root->right = buildFromPreIn(
        preorder, inorder,
        preStart + 1 + leftSubtreeSize, idx + 1, inEnd
    );

    return root;
}

// Build tree from preorder and inorder arrays
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    // Build map: value -> index in inorder
    for (int i = 0; i < inorderSize; i++) {
        map[inorder[i] + OFFSET] = i;
    }

    return buildFromPreIn(preorder, inorder, 0, 0, inorderSize - 1);
}

// Simple BFS style level‑order print (null shown as "N")
void printLevelOrder(struct TreeNode* root) {
    if (!root) {
        printf("[]\n");
        return;
    }

    struct TreeNode* queue[10000];
    int front = 0, rear = 0;

    queue[rear++] = root;

    printf("[");
    int first = 1;

    while (front < rear) {
        struct TreeNode* node = queue[front++];
        if (node) {
            if (!first) printf(",");
            printf("%d", node->val);
            first = 0;

            queue[rear++] = node->left;
            queue[rear++] = node->right;
        } else {
            if (!first) printf(",");
            printf("null");
            first = 0;
        }
    }
    printf("]\n");
}

// Driver code
int main() {
    // Example 1
    int preorder[] = {3, 9, 20, 15, 7};
    int inorder[]  = {9, 3, 15, 20, 7};
    int n = 5;

    struct TreeNode* root = buildTree(preorder, n, inorder, n);

    printf("Tree: ");
    printLevelOrder(root);

    // Example 2
    int preorder2[] = {-1};
    int inorder2[]  = {-1};
    int n2 = 1;

    struct TreeNode* root2 = buildTree(preorder2, n2, inorder2, n2);

    printf("Tree 2: ");
    printLevelOrder(root2);

    return 0;
}
