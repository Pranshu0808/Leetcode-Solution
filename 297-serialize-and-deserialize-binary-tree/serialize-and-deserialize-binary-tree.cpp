/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string serialize(TreeNode* root) {
        if(root == NULL){
            return "";
        }

        string s = "";
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(node == NULL){
                s += "#,";
                continue;
            }

            s += to_string(node->val);
            s += ",";

            q.push(node->left);
            q.push(node->right);
        }

        return s;
    }
    TreeNode* deserialize(string data) {
        if(data.size() == 0){
            return NULL;
        }

        vector<string> v;
        string t = "";

        for(int i = 0; i < data.size(); i++){
            if(data[i] == ','){
                v.push_back(t);
                t = "";
            }
            else{
                t += data[i];
            }
        }

        TreeNode* root = new TreeNode(stoi(v[0]));
        queue<TreeNode*> q;
        q.push(root);

        int i = 1;

        while(!q.empty() && i < v.size()){
            TreeNode* node = q.front();
            q.pop();

            if(v[i] != "#"){
                node->left = new TreeNode(stoi(v[i]));
                q.push(node->left);
            }
            i++;

            if(i < v.size() && v[i] != "#"){
                node->right = new TreeNode(stoi(v[i]));
                q.push(node->right);
            }
            i++;
        }

        return root;
    }
};
