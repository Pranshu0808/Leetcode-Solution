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
    vector<int> rightSideView(TreeNode* root){
        vector<int> ans;
        map<int , int> m;
        queue<pair<TreeNode* , int>> q;
        if(root == NULL){
            return ans;
        }
        q.push({root , 0});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            TreeNode* node = it.first;
            int line = it.second;
            if(m.find(line) == m.end()){
                m[line] = node->val;
            }
            if(node->right != NULL){
                q.push({node->right , line + 1});
            }
            if(node->left != NULL){
                q.push({node->left , line + 1});
            }
            
        }
        for(auto it = m.begin(); it != m.end(); ++it){
            ans.push_back(it->second);
        }
        return ans;
    }
};