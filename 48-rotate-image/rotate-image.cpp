class Solution {
public:
    void rotate(vector<vector<int>>& v){
        int n = v.size();
        vector<vector<int>> v1(n , vector<int>(n));
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                v1[i][j] = v[j][i];
            }
        }
        for(int i = 0; i < v1.size(); ++i){
            reverse(v1[i].begin(), v1[i].end());
        }

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                v[i][j] = v1[i][j];
            }
        }


    }
};