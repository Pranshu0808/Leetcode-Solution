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
    int dfs(TreeNode* root , unordered_map<int , int>& m){
        if(root == NULL){
            return 0;
        }
        int leftsum = dfs(root->left , m);
        int rightsum = dfs(root->right , m);
        m[(root->val + leftsum + rightsum)]++;
        return (root->val + leftsum + rightsum);
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int , int> m;
        vector<int> v;
        dfs(root , m);
        int maxFreq = 0;
        for(auto it = m.begin(); it != m.end(); it++){
            maxFreq = max(maxFreq, it->second);
        }

        for(auto it = m.begin(); it != m.end(); it++){
            if(maxFreq == it->second){
                v.push_back(it->first);
            }
        }
        return v;



    }
};