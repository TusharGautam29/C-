/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
TreeNode* solve(int &Postindex,int inI,int inJ,vector<int>&inorder, vector<int>&postorder)
{
    if(Postindex<0 || inI>inJ) return NULL;
    TreeNode* root=new TreeNode(postorder[Postindex--]);
    int i;
    for( i=inI;i<=inJ;i++) if(inorder[i]==root->val) break;
    root->right=solve(Postindex,i+1,inJ,inorder,postorder); 
     root->left=solve(Postindex,inI,i-1,inorder,postorder);
    return root;
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int index=postorder.size()-1;
        return solve(index,0,inorder.size()-1,inorder,postorder);
    }
};