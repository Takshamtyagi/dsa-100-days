#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for a binary tree node (LeetCode style).
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new node
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Build BST from level order array (nulls skipped)
struct TreeNode* buildBST(int* nums, int numsSize) {
    if (numsSize == 0) return NULL;
    
    struct TreeNode** queue = (struct TreeNode**)malloc(numsSize * sizeof(struct TreeNode*));
    int front = 0, rear = 0;
    
    struct TreeNode* root = createNode(nums[0]);
    queue[rear++] = root;
    
    int i = 1;
    while (front < rear && i < numsSize) {
        struct TreeNode* curr = queue[front++];
        
        // Left child
        if (nums[i] != -999) {  // Use -999 as null marker
            curr->left = createNode(nums[i]);
            queue[rear++] = curr->left;
        }
        i++;
        
        // Right child
        if (i < numsSize && nums[i] != -999) {
            curr->right = createNode(nums[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }
    
    free(queue);
    return root;
}

// LeetCode solution: Iterative LCA using BST property
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    struct TreeNode* curr = root;
    while (curr != NULL) {
        if (p->val < curr->val && q->val < curr->val) {
            curr = curr->left;
        } else if (p->val > curr->val && q->val > curr->val) {
            curr = curr->right;
        } else {
            return curr;
        }
    }
    return NULL;  // Won't happen per constraints
}

// Utility to print inorder (for verification)
void inorder(struct TreeNode* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

// Free tree memory
void freeTree(struct TreeNode* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    // Example 1: root = [6,2,8,0,4,7,9,null,null,3,5], p=2, q=8
    int nums1[] = {6,2,8,0,4,7,9,-999,-999,3,5};
    struct TreeNode* root1 = buildBST(nums1, 11);
    struct TreeNode* p1 = root1->left;      // 2
    struct TreeNode* q1 = root1->right;     // 8
    struct TreeNode* lca1 = lowestCommonAncestor(root1, p1, q1);
    printf("LCA(2,8): %d\n", lca1->val);  // 6
    
    // Example 2: p=2, q=4
    struct TreeNode* p2 = root1->left->right->right;  // 4 (reuse tree)
    struct TreeNode* lca2 = lowestCommonAncestor(root1, p1, p2);
    printf("LCA(2,4): %d\n", lca2->val);  // 2
    
    // Example 3
    int nums3[] = {2,1};
    struct TreeNode* root3 = buildBST(nums3, 2);
    struct TreeNode* p3 = root3;           // 2
    struct TreeNode* q3 = root3->left;     // 1
    struct TreeNode* lca3 = lowestCommonAncestor(root3, p3, q3);
    printf("LCA(2,1): %d\n", lca3->val);  // 2
    
    freeTree(root1);
    freeTree(root3);
    return 0;
}
