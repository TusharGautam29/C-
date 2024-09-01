class Solution {
public:
    void display(TreeNode* root,int &ans){
        if(root==NULL) return;
        ans=min(ans,(root->val));
        display(root->left,ans);
        display(root->right,ans);
    }
    int minvalue(TreeNode* root) {
        int ans=INT_MAX;
        display(root,ans);
        return ans;
    }
};