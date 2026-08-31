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
    TreeNode* recoverFromPreorder(string traversal) {
        vector<pair<int, int>> arr;
        int i = 0;
        while(i < traversal.size()){
            int level = 0;
            while(i < traversal.size() && traversal[i] == '-'){
                level++;
                i++;
            }
            int num = 0;
            while(i < traversal.size() && traversal[i] != '-'){
                num = num * 10 + (traversal[i] - '0');
                i++;
            }
            arr.push_back({level, num});
        }

        TreeNode* root = new TreeNode(arr[0].second);
        map<int, TreeNode*> mp;
        mp[0] = root;

        for (int i = 1; i < arr.size(); i++) {
            int parentLevel = arr[i].first - 1;
            TreeNode* node = new TreeNode(arr[i].second);
            mp[arr[i].first] = node;

            if (!mp[parentLevel]->left) {
                mp[parentLevel]->left = node;
            } else {
                mp[parentLevel]->right = node;
            }
        }
        
        return root;

    }
};