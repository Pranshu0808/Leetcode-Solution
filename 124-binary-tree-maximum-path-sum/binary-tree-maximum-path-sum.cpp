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
    int mxPath(TreeNode* node , int &maxi){
        if(node == NULL){
            return 0;
        }

        int lftsum = max(0, mxPath(node->left, maxi));
        int rgtsum = max(0 ,mxPath(node->right, maxi));

        maxi = max(maxi , lftsum+rgtsum+node->val);
        return  max(lftsum , rgtsum) + node->val;

    }
    int maxPathSum(TreeNode* root){
        int maxi = INT_MIN;
        mxPath(root ,maxi);
        return maxi;
    }
};