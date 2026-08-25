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
     void calinorder(int& presum , int& sum  , TreeNode*& root){
        if(root == NULL){
            return;
        }
        calinorder(presum , sum , root->left);
        int x = root->val;
        root->val = sum - presum;
        presum += x;
        calinorder(presum , sum , root->right);
    }
    void inorder(int& sum , TreeNode*& root){
        if(root == NULL){
            return;
        }
        inorder(sum , root->left);
        sum += root->val;
        inorder(sum , root->right);
    }

    TreeNode* convertBST(TreeNode* root) {
        TreeNode* node = root;
        int sum = 0;
        inorder(sum , root);
        int presum = 0;
        calinorder(presum , sum , root);
        return node;
    }
};

