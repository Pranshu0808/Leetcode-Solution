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
    vector<vector<int>> verticalTraversal(TreeNode* root){
        map<int , map<int , multiset<int>>> m;
        queue<pair<TreeNode* , pair < int , int >>> todo;
        todo.push({root , {0 , 0}});
        while(!todo.empty()){
            auto p = todo.front();
            todo.pop();
            TreeNode* node = p.first;
            int x = p.second.first; int y = p.second.second;
            m[x][y].insert(node->val);
            if(node->left != NULL){
                todo.push({node->left , {x-1 , y + 1}});
            }
            if(node->right != NULL){
                todo.push({node->right, {x+1 , y + 1}});
            }
        }
        vector<vector<int>> ans;
        for(auto p = m.begin(); p != m.end(); ++p){
            vector<int> col;
            for(auto q = p->second.begin(); q != p->second.end(); ++q){
                for(auto it = q->second.begin(); it != q->second.end(); ++it){
                    col.push_back(*it);
                }
            }
            ans.push_back(col);
        }
        return ans;
    }
};