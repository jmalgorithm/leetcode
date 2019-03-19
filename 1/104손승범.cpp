/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int find(TreeNode* root, int deep){
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        if(root==NULL)
            return deep;
        TreeNode *l=root->left;
        TreeNode *r=root->right;
        return max(find(l,deep+1),find(r,deep+1));
    }
    int maxDepth(TreeNode* root) {
        return find(root,0);
    }
};