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
    int minimumOperations(TreeNode* root){
        int ct = 0;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){

            int sz = q.size();
            vector<int> level;

            for(int i = 0; i < sz; ++i){

                TreeNode* node = q.front();
                q.pop();

                if(node->left != NULL){
                    q.push(node->left);
                }

                if(node->right != NULL){
                    q.push(node->right);
                }

                level.push_back(node->val);
            }
            vector<int> temp = level;
            sort(temp.begin(), temp.end());
            for(int i = 0; i < temp.size(); ++i){
                while(temp[i] != level[i]){
                    int pos = lower_bound(
                        temp.begin(),
                        temp.end(),
                        level[i]
                    ) - temp.begin();

                    swap(level[i], level[pos]);
                    ct++;
                }
            }
        }

        return ct;
    }
};