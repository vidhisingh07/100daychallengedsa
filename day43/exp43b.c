#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void inorder(struct TreeNode* root, int* result, int* index) {
    if (root == NULL) return;

    inorder(root->left, result, index);   // Left
    result[*index] = root->val;           // Root
    (*index)++;
    inorder(root->right, result, index);  // Right
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(100 * sizeof(int)); // assume max 100 nodes
    int index = 0;

    inorder(root, result, &index);

    *returnSize = index;
    return result;
}