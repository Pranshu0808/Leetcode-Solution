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
    vector<TreeNode*> dfs(int n){
        if(n == 1){
            TreeNode* root = new TreeNode(0);
            return {root};
        }
        vector<TreeNode*> ans;
        for(int left = 1; left < n; left += 2){
            int right = n - 1 - left;
            vector<TreeNode*> leftTrees = dfs(left);
            vector<TreeNode*> rightTrees = dfs(right);
            for(int i = 0; i < leftTrees.size(); i++){
                for(int j = 0; j < rightTrees.size(); j++){
                    TreeNode* root = new TreeNode(0);

                    root->left = leftTrees[i];
                    root->right = rightTrees[j];

                    ans.push_back(root);
                }
            }
        }
        return ans;
    }

    vector<TreeNode*> allPossibleFBT(int n){
        if(n % 2 == 0){
            return {};
        }
        return dfs(n);
    }
};