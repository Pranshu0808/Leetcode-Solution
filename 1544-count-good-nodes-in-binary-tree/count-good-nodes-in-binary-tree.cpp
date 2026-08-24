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
    int ct = 0;
    void dfs(TreeNode* root , int mx){
        if(root == NULL){
            mx = 0;
            return;
        }
        mx = max(mx , root->val);
        if(mx == root->val){
            ct++;
        }
        
        dfs(root->left  , mx);
        dfs(root->right , mx);
    }
    int goodNodes(TreeNode* root){
        
        int mx = INT_MIN;
        dfs(root , mx);
        return ct;
    }
};