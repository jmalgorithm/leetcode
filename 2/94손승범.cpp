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
    vector<int> inorderTraversal(TreeNode* root) {
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        vector<int> result,v;
        if(root==NULL)
            return result; 
        result=inorderTraversal(root->left);
        result.push_back(root->val);
        v=inorderTraversal(root->right);
        for(int i=0;i<v.size();i++){
            result.push_back(v[i]);
        }
        return result;
    }
};