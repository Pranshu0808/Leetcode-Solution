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
    int count = 0;
    void dfs(TreeNode* root, int dist, vector<int>& leaves) {
        if(root == NULL){
            return;
        }
        if(root->left == NULL && root->right == NULL){
            leaves.push_back(dist);
            return;
        }

        dfs(root->left, dist + 1, leaves);
        dfs(root->right, dist + 1, leaves);
    }

    void inorder(TreeNode* root, int& distance) {
        if(root == NULL){
            return;
        }
        inorder(root->left, distance);
        vector<int> leftLeaves;
        dfs(root->left, 1, leftLeaves);
        vector<int> rightLeaves;
        dfs(root->right, 1, rightLeaves);
        for(int i = 0; i < leftLeaves.size(); i++){
            for(int j = 0; j < rightLeaves.size(); j++){
                if(leftLeaves[i] + rightLeaves[j] <= distance){
                    count++;
                }
            }
        }
        inorder(root->right, distance);
    }

    int countPairs(TreeNode* root, int distance) {
        inorder(root, distance);
        return count;
    }
};