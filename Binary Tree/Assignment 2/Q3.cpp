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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()>0){
            int k=q.size();
            vector<int> level;
            for(int i=0;i<k;i++){
                TreeNode* temp=q.front();
                q.pop();
                level.push_back(temp->val);

                if(temp->right) q.push(temp->right);
                if(temp->left) q.push(temp->left);
                
            }
            ans.push_back(level);
        }
        return ans;
    }
};