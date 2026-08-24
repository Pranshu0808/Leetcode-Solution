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
    void dfs(TreeNode*& root ,TreeNode*& node , int& mx){
        if(root == NULL){
            return;
        }
        dfs(root->left ,node ,  mx);
        dfs(root->right , node , mx);
        mx = max(mx , root->val);
        
    }
    void inorder(TreeNode*& root){
        if(root == NULL){
            return;
        }
        inorder(root->left);
        int mx = -1;
        dfs(root , root ,  mx);
        if(mx == root->val){
            ct++;
        }
        inorder(root->right);
    }
    int countDominantNodes(TreeNode* root) {
        inorder(root);
        return ct;
    }
};