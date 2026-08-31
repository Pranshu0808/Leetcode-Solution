/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(root == NULL){
            return ans;
        }
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            vector<int> level;
            for(int i = 0; i < sz; ++i){
                Node* node = q.front();
                q.pop();
                for(int j = 0 ; j < node->children.size(); ++j){
                    Node* child = node->children[j];
                    q.push(child);
                }
                level.push_back(node->val);
            }
            ans.push_back(level);
        }
        return ans;
    }
};