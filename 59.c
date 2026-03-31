#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int x) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = x;
    node->left = node->right = NULL;
    return node;
}

// Find index of 'value' in inorder[inStart ... inEnd]
int search(int inorder[], int inStart, int inEnd, int value) {
    int i;
    for (i = inStart; i <= inEnd; i++) {
        if (inorder[i] == value) return i;
    }
    return -1;
}

// Recursive tree builder
Node *buildUtil(int inorder[], int postorder[],
                int inStart, int inEnd,
                int *pIndex) {
    if (inStart > inEnd) return NULL;

    // Pick root from postorder (last unused)
    Node *root = createNode(postorder[*pIndex]);
    (*pIndex)--;

    if (inStart == inEnd) return root;

    // Find root index in inorder
    int inIndex = search(inorder, inStart, inEnd, root->data);

    // Build right subtree first, then left
    root->right = buildUtil(inorder, postorder, inIndex + 1, inEnd, pIndex);
    root->left  = buildUtil(inorder, postorder, inStart,   inIndex - 1, pIndex);

    return root;
}

Node *buildTree(int inorder[], int postorder[], int n) {
    int pIndex = n - 1;
    return buildUtil(inorder, postorder, 0, n - 1, &pIndex);
}

// Preorder traversal (root, left, right)
void preorder(Node *root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Inorder traversal (for sanity check)
void inorder(Node *root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    // Example: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
    int inorder[] = {9, 3, 15, 20, 7};
    int postorder[] = {9, 15, 7, 20, 3};
    int n = sizeof(inorder) / sizeof(inorder[0]);

    Node *root = buildTree(inorder, postorder, n);

    printf("Preorder  : ");
    preorder(root);
    printf("\n");

    printf("Inorder   : ");
    inorder(root);
    printf("\n");

    return 0;
}
