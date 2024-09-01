class Solution {
public:
    void display(TreeNode* root,int &ans){
        if(root==NULL) return;
        ans=ans*(root->val);
        display(root->left,ans);
        display(root->right,ans);
    }
    int preorderTraversal(TreeNode* root) {
        int ans=1;
        display(root,ans);
        return ans;
    }
};