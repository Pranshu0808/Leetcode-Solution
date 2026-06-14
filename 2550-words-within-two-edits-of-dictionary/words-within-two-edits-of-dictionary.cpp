class Solution {
public:
    vector<string> twoEditWords(vector<string>& q, vector<string>& dict) {
        vector<string> v;
        int Q = q.size();
        int m = dict.size();
        for(int i = 0; i < Q; ++i){
            for(int j = 0; j < m; ++j){
                int ct = 0;
                for(int k = 0; k < q[i].size(); ++k){
                    if(q[i][k] != dict[j][k]){
                        ct++;
                    }
                }
                if(ct <= 2){
                    v.push_back(q[i]);
                    break;
                }
            }
        }
        return v;
    }
};