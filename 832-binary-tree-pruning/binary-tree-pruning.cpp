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
    bool dfs(TreeNode*& root ){
        if(root == NULL){
            return false;
        }
        bool lh = dfs(root->left);
        bool rh = dfs(root->right);
        if(root->val == 1 || lh == true || rh == true) {
            return true;
        }
        root = NULL;
        return false;
    }
    TreeNode* pruneTree(TreeNode* root) {
        TreeNode* node = root;
        dfs(root);
        return root;
    }
};