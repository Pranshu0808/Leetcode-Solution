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
    int ans;
    int mxLevel = -1;
    void inorder(TreeNode* root, int level){
        if(root == NULL){
            return;
        }
        inorder(root->left, level + 1);
        if(level > mxLevel){
            mxLevel = level;
            ans = root->val;
        }
        inorder(root->right, level + 1);
    }

    int findBottomLeftValue(TreeNode* root) {
        inorder(root, 0);
        return ans;
    }
};