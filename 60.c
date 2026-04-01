#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Helper: check if current subtree satisfies min-heap property
bool isMinHeapHelper(struct TreeNode *node) {
    if (!node) return true;

    // Check left child
    if (node->left != NULL) {
        if (node->val > node->left->val) {
            return false;
        }
    }

    // Check right child
    if (node->right != NULL) {
        if (node->val > node->right->val) {
            return false;
        }
    }

    // Recursively check both subtrees
    return isMinHeapHelper(node->left) && isMinHeapHelper(node->right);
}

// Main function: check whether the entire tree satisfies min-heap property
bool isMinHeap(struct TreeNode *root) {
    return isMinHeapHelper(root);
}
