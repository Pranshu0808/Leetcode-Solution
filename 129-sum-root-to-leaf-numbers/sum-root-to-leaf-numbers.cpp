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
    void dfs(TreeNode* root , string& s){
        if(root == NULL){
            return;
        }
        s.push_back(root->val + '0');
        dfs(root->left , s);
        dfs(root->right , s);
        if(root->left == NULL && root->right == NULL){
            ct = ct + stoi(s);
        }
        s.pop_back();
    }
    int sumNumbers(TreeNode* root) {
        string s = "";
        dfs(root , s);
        return ct;
        
    }
};