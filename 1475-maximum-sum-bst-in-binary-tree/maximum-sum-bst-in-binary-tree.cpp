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

    class NodeValue{
    public:
        int mn, mx, sum;

        NodeValue(int mn, int mx, int sum){
            this->mn = mn;
            this->mx = mx;
            this->sum = sum;
        }
    };

    int ans = 0;

    NodeValue solve(TreeNode* root){

        if(root == NULL){
            return NodeValue(INT_MAX, INT_MIN, 0);
        }

        NodeValue l = solve(root->left);
        NodeValue r = solve(root->right);

        if(l.mx < root->val && root->val < r.mn){

            int currSum = l.sum + r.sum + root->val;
            ans = max(ans, currSum);

            return NodeValue(
                min(l.mn, root->val),
                max(r.mx, root->val),
                currSum
            );
        }

        return NodeValue(INT_MIN, INT_MAX, max(l.sum, r.sum));
    }

    int maxSumBST(TreeNode* root) {

        solve(root);
        return ans;
    }
};