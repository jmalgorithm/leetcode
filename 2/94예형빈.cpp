class Solution { 
   
    public: 
    void findAnswer(TreeNode* root,vector<int>& answer){
        if(root!=nullptr){
        if(root->left != nullptr)
            findAnswer(root->left,answer);
        answer.push_back(root->val);
        if(root->right != nullptr)
            findAnswer(root->right,answer);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> answer;
        findAnswer(root,answer);
        return answer;
    }
   
};