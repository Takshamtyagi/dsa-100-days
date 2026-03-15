#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* buildTree(int* nums, int numsSize) {
    if (numsSize == 0) return NULL;
    
    struct TreeNode* root = createNode(nums[0]);
    
    // Use array as queue for simplicity (max 100 nodes)
    struct TreeNode* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    
    int i = 1;
    while (front < rear && i < numsSize) {
        struct TreeNode* curr = queue[front++];
        
        // Left child
        if (i < numsSize) {
            curr->left = createNode(nums[i]);
            queue[rear++] = curr->left;
            i++;
        }
        
        // Right child
        if (i < numsSize) {
            curr->right = createNode(nums[i]);
            queue[rear++] = curr->right;
            i++;
        }
    }
    
    return root;
}
