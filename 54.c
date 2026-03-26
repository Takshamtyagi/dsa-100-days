#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

int treeHeight(struct Node* root) {
    if (!root) return 0;
    int l = treeHeight(root->left);
    int r = treeHeight(root->right);
    return (l > r ? l : r) + 1;
}

void leftToRightLevel(struct Node* root, int level) {
    if (!root) return;
    if (level == 1) {
        printf("%d ", root->data);
    } else {
        leftToRightLevel(root->left, level - 1);
        leftToRightLevel(root->right, level - 1);
    }
}

void rightToLeftLevel(struct Node* root, int level) {
    if (!root) return;
    if (level == 1) {
        printf("%d ", root->data);
    } else {
        rightToLeftLevel(root->right, level - 1);
        rightToLeftLevel(root->left, level - 1);
    }
}

void zigzagLevelOrder(struct Node* root) {
    if (!root) return;

    int h = treeHeight(root);
    bool leftToRight = true;

    for (int i = 1; i <= h; i++) {
        if (leftToRight) {
            leftToRightLevel(root, i);
        } else {
            rightToLeftLevel(root, i);
        }
        leftToRight = !leftToRight;
    }
}

int main() {
    // Example tree:
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5

    struct Node* root = createNode(1);
    root->left        = createNode(2);
    root->right       = createNode(3);
    root->left->left  = createNode(4);
    root->left->right = createNode(5);

    printf("Zigzag level order: ");
    zigzagLevelOrder(root);
    printf("\n");

    return 0;
}
