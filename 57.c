#include <stdio.h>
#include <stdlib.h>

// Structure of a node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to convert to mirror tree
void mirror(struct Node* root) {
    if (root == NULL)
        return;

    // swap left and right
    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // recur for left and right subtrees
    mirror(root->left);
    mirror(root->right);
}

// Inorder traversal (to check result)
void inorder(struct Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Main function
int main() {
    /*
            1
           / \
          2   3
         / \
        4   5
    */

    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Inorder before mirror:\n");
    inorder(root);

    mirror(root);

    printf("\nInorder after mirror:\n");
    inorder(root);

    return 0;
}
