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
    void inorder(TreeNode* root , int k , set<int>& s){
        if(root == NULL){
            return;
        }
        inorder(root->left , k , s);
        s.insert(root->val);
        inorder(root->right, k , s);
    }
    bool findTarget(TreeNode* root, int k){
        set<int> s;
        inorder(root , k , s);
        for(auto it = s.begin(); it != s.end(); ++it){
            if(s.find(k-*it) != s.end() && (k-*it) != *it){
                return true;
            }
        }
        return false;
    }
};