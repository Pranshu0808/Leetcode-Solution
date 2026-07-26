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
    int i = 0;

    TreeNode* solve(vector<int>& p, int l, int r){
        if(i == p.size() || p[i] < l || p[i] > r)
            return NULL;

        TreeNode* root = new TreeNode(p[i]);
        i++;

        root->left = solve(p, l, root->val);
        root->right = solve(p, root->val, r);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return solve(preorder, INT_MIN, INT_MAX);
    }
};