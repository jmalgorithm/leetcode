/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int count = 0;
int search(struct TreeNode* root, int count1){
    int cnt = count1+1;
    int a,b;
    if(root != NULL && root->left == NULL ){
        return cnt;
    }
    else if(root != NULL && root->left != NULL ){
      a = search(root->left,cnt);
    }
    else if(root != NULL &&root->right != NULL ){
      b = search(root->right,cnt);
    }
    return (a>b? a:b);
}
int maxDepth(struct TreeNode* root) {
    count=count+1;
    int cnt=count;
    int a,b;
    if(root == NULL){
        return 0;
    }
    else if(root->left == NULL && root->right ==NULL && root != NULL){
        return count;
    }
    else{
        a = search(root->left,cnt);
        b = search(root->right,cnt);
        return (a>b? a:b);
    }    
}

