#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Create a new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Helper: check if left and right subtrees are mirror images
bool isMirror(struct TreeNode* left, struct TreeNode* right) {
    if (left == NULL && right == NULL) {
        return true;
    }
    if (left == NULL || right == NULL) {
        return false;
    }
    return (left->val == right->val) &&
           isMirror(left->left, right->right) &&
           isMirror(left->right, right->left);
}

// Main function: check if the whole tree is symmetric
bool isSymmetric(struct TreeNode* root) {
    if (root == NULL) {
        return true;
    }
    return isMirror(root->left, root->right);
}

// Example usage
int main() {
    // Example 1: [1,2,2,3,4,4,3] -> true
    struct TreeNode* root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(2);
    root1->left->left = newNode(3);
    root1->left->right = newNode(4);
    root1->right->left = newNode(4);
    root1->right->right = newNode(3);

    if (isSymmetric(root1)) {
        printf("Example 1: true\n");
    } else {
        printf("Example 1: false\n");
    }

    // Example 2: [1,2,2,null,3,null,3] -> false
    struct TreeNode* root2 = newNode(1);
    root2->left = newNode(2);
    root2->right = newNode(2);
    root2->left->right = newNode(3);
    root2->right->right = newNode(3);

    if (isSymmetric(root2)) {
        printf("Example 2: true\n");
    } else {
        printf("Example 2: false\n");
    }

    return 0;
}
