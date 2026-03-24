#include <stdio.h>
#include <stdlib.h>

// Tree node structure
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Helper function to create new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Find LCA function
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, 
                                     struct TreeNode* p, 
                                     struct TreeNode* q) {
    // Base case: if root is null or root is p or q
    if (root == NULL || root == p || root == q) {
        return root;
    }
    
    // Recursively find in left subtree
    struct TreeNode* left = lowestCommonAncestor(root->left, p, q);
    
    // Recursively find in right subtree
    struct TreeNode* right = lowestCommonAncestor(root->right, p, q);
    
    // If both p and q found in different subtrees, root is LCA
    if (left != NULL && right != NULL) {
        return root;
    }
    
    // Return non-null result from left or right subtree
    return (left != NULL) ? left : right;
}

// Helper function to print tree (preorder)
void printTree(struct TreeNode* root) {
    if (root == NULL) return;
    printf("%d ", root->val);
    printTree(root->left);
    printTree(root->right);
}

// Driver code with test cases
int main() {
    // Example 1: [3,5,1,6,2,0,8,null,null,7,4], p=5, q=1
    struct TreeNode *root = newNode(3);
    root->left = newNode(5);
    root->right = newNode(1);
    root->left->left = newNode(6);
    root->left->right = newNode(2);
    root->right->left = newNode(0);
    root->right->right = newNode(8);
    root->left->right->left = newNode(7);
    root->left->right->right = newNode(4);
    
    struct TreeNode *p = root->left;        // 5
    struct TreeNode *q = root->right;       // 1
    
    printf("Tree: ");
    printTree(root);
    printf("\nLCA of %d and %d: %d\n", p->val, q->val, 
            lowestCommonAncestor(root, p, q)->val);  // Output: 3
    
    // Example 2: p=5, q=4
    p = root->left;                         // 5
    q = root->left->right->right;           // 4
    printf("LCA of %d and %d: %d\n", p->val, q->val, 
           lowestCommonAncestor(root, p, q)->val);  // Output: 5
    
    // Example 3: [1,2], p=1, q=2
    struct TreeNode *root2 = newNode(1);
    root2->left = newNode(2);
    printf("\nTree2: ");
    printTree(root2);
    printf("\nLCA of %d and %d: %d\n", root2->val, root2->left->val,
           lowestCommonAncestor(root2, root2, root2->left)->val);  // Output: 1
    
    return 0;
}
