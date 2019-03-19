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
    int maxDepth(TreeNode* root) {
        return count(root,0);
    }
    
    int count(TreeNode* root,int num){
       if(root==nullptr)
           return num;
        int a = count(root->left,num+1);
        int b = count(root->right,num+1);
        if(a>b)
            return a;
        return b;
    }
    
};