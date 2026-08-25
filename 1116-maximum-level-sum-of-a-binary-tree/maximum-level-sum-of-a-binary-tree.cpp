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
    int maxLevelSum(TreeNode* root) {
        if(root == NULL){
            return -1;
        }
        queue<TreeNode*> q;
        q.push(root);
        vector<int> level;
        while(!q.empty()){
            int sum = 0;
            int sz = q.size();
            for(int i = 0 ; i < sz; ++i){
                TreeNode* node = q.front();
                q.pop();
                if(node->left != NULL){
                    q.push(node->left);
                }
                if(node->right != NULL){
                    q.push(node->right);
                }
                sum += node->val;
            }
            level.push_back(sum);
        }
        int ind = max_element(level.begin() , level.end()) - level.begin();
        return ind+1;
    }
};