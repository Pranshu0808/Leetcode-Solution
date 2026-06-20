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
    void dfs_pr(TreeNode* node , vector<int> &v){
        if(node == NULL){
            return;
        }
        v.push_back(node->val);
        dfs_pr(node->left , v);
        dfs_pr(node->right, v);

    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        dfs_pr(root , v);
        return v;
    }
};