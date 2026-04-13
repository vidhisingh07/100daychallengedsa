#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void preorder(struct TreeNode* root, int** result, int* size, int* capacity) {
    if (root == NULL) return;

    // Add root first
    if (*size >= *capacity) {
        *capacity *= 2;
        *result = (int*)realloc(*result, (*capacity) * sizeof(int));
    }

    (*result)[(*size)++] = root->val;

    preorder(root->left, result, size, capacity);  // Left
    preorder(root->right, result, size, capacity); // Right
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int capacity = 10;
    int* result = (int*)malloc(capacity * sizeof(int));
    int size = 0;

    preorder(root, &result, &size, &capacity);

    *returnSize = size;
    return result;
}