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
    void inorder(TreeNode* nd , TreeNode* node ,  int& mx){
        if(nd == NULL){
            return;
        }
        inorder(nd->left ,node , mx);
        mx = max(mx , abs(node->val - nd->val));
         inorder(nd->right, node  , mx);

    }

    void preorder(TreeNode* root , int& ans){
        if(root == NULL){
            return;
        }
        int mx = 0;
        TreeNode* node = root;
        TreeNode* nd = root;
        inorder(nd , node , mx);
        ans = max(ans , mx);
        preorder(root->left , ans);
        preorder(root->right , ans);

    }
    int maxAncestorDiff(TreeNode* root){
        int ans = INT_MIN;
        preorder(root , ans);
        return ans;
    }
};