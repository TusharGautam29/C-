class Solution {
    int level(TreeNode* root) {
        if(root == NULL) return 0;
        return 1+max(level(root->right),level(root->left));
    }
    int maxdia=0;

public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        int dia= level(root->left)+ level(root->right);
        maxdia=max(dia,maxdia);
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        return maxdia;
    }
};