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
    void dfs(TreeNode*& root , set<int>& s , queue<TreeNode*>& q){
        if(root == NULL){
            return;
        }
        if(s.find(root->val) != s.end()){
            s.erase(root->val);
            if(root->left != NULL){
                q.push(root->left); 
            }
            if(root->right != NULL){
                q.push(root->right);
            }
            root = NULL;
            return;
        }
        dfs(root->left , s , q);
        dfs(root->right , s , q);
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete){
        set<int> s;
        for(int i = 0 ; i < to_delete.size(); ++i){
            s.insert(to_delete[i]);
        }
        vector<TreeNode*> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            dfs(node ,s , q);
            if(node != NULL){
            ans.push_back(node);
            }
        }

        return ans;
    }
};