/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth2(struct TreeNode* root, int height) {
    if (root == NULL) {
        return height;
    } else {
        int h_right, h_left;
        h_right = maxDepth2(root->right, height + 1);
        h_left = maxDepth2(root->left, height + 1);
        return (h_right > h_left) ? h_right : h_left;
    }
}

int maxDepth(struct TreeNode* root) {
    return maxDepth2(root, 0);
}
