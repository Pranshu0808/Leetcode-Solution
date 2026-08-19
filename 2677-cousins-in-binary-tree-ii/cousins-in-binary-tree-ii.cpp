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
    TreeNode* replaceValueInTree(TreeNode* root){
        TreeNode* node = root;
        queue<TreeNode*> q;
        q.push(node);
        vector<int> v;
        while(!q.empty()){
        
             int sz = q.size();
             int sum = 0;
             for(int i = 0 ; i < sz; ++i){
                TreeNode* curr = q.front();
                q.pop();
                sum += curr->val;
                if(curr->left != NULL){
                    q.push(curr->left);
                }
                if(curr->right != NULL){
                    q.push(curr->right);
                }
             }
             v.push_back(sum);
        }
        int j = 1;
        q.push(node);
        while(!q.empty()){
             int sz = q.size();
             
             for(int i = 0 ; i < sz; ++i){
                TreeNode* curr = q.front();
                q.pop();
                int sum = 0;
                if(curr->left != NULL){
                    sum += curr->left->val;
                    q.push(curr->left);
                }
                if(curr->right != NULL){
                    sum += curr->right->val;
                    q.push(curr->right);
                }

                if(curr->left != NULL){
                    curr->left->val = v[j]-sum;
                }
                if(curr->right != NULL){
                    curr->right->val = v[j]-sum;
                }
             }
             j++;
        }
        node->val = 0;
        return node;

    }
};