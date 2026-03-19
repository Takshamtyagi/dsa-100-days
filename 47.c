#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// TreeNode definition matching LeetCode
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Recursive max depth function (LeetCode solution)
int maxDepth(struct TreeNode* root) {
    if (root == NULL) return 0;
    return 1 + (int)fmax(maxDepth(root->left), maxDepth(root->right));
}

// Helper to create node
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Build tree from level-order array (like LeetCode input)
struct TreeNode* buildTree(int* nums, int numsSize) {
    if (numsSize == 0) return NULL;
    
    struct TreeNode* root = createNode(nums[0]);
    int* queue = (int*)malloc(numsSize * sizeof(int));  // Index queue for BFS
    int front = 0, rear = 0;
    queue[rear++] = 0;
    
    int i = 1;
    while (front < rear && i < numsSize) {
        int currIdx = queue[front++];
        struct TreeNode* curr = /* Simulate access via index, but since dynamic tree, use queue of pointers? Wait, better pointer queue */
Wait, for simplicity, here's corrected pointer-based queue version:
    
    // Corrected build function using pointer queue
struct TreeNode** queue = (struct TreeNode**)malloc(numsSize * sizeof(struct
