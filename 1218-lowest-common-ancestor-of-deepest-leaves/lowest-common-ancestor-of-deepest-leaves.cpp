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

        TreeNode* LCA(TreeNode* root , set<TreeNode*>& v){
        if(root == NULL || v.find(root) != v.end() ){
            return root;
        }
        TreeNode* left = LCA(root->left , v);
        TreeNode* right = LCA(root->right , v);
        if(left == NULL){
            return right;
        }
        if(right == NULL){
            return left;
        }
        else{
            return root;
        }

    }

    TreeNode* lcaDeepestLeaves(TreeNode* root){
        if(root == NULL){
            return NULL;
        }
        set<TreeNode*> v;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            v.clear();
            int sz = q.size();
            for(int i = 0; i < sz; ++i){
                TreeNode* node = q.front();
                q.pop();
                if(node->left != NULL){
                    q.push(node->left);
                }
                if(node->right != NULL){
                    q.push(node->right);
                }
                v.insert(node);
            }
        }
        
        return LCA(root ,v);
    }
};