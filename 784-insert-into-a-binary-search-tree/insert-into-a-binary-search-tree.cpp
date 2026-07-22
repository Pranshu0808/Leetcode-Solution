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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL){
            return new TreeNode(val);
        }
        TreeNode* temp = root;
        TreeNode* node = root;
        while(root != NULL){
            node = root;
            if(root->val < val){
                root = root->right;
            }
            else{
                root = root->left;
            }
        }
        if(node->val < val){
            node->right = new TreeNode(val);
        }
        else{
            node->left = new TreeNode(val);
        }
        return temp;
    }
};