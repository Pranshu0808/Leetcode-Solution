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
    int ans = 0;
    void maxx(TreeNode* node , int depth){
        if(node == NULL){
            ans = max(ans , depth);
            return;
        }

        maxx(node->left , depth+1);
        maxx(node->right , depth+1);

    }
    int maxDepth(TreeNode* root){
        maxx(root , 0);
        return ans;
    }
};