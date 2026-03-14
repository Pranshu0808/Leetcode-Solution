class Solution {
public:
    void rotate(vector<vector<int>>& v){
        int n = v.size();
        // vector<vector<int>> v1(n , vector<int>(n));
        for(int i = 0; i < n; ++i){
            for(int j = i+1; j < n; ++j){
                swap(v[i][j] , v[j][i]);
            }
        }
        for(int i = 0; i < v.size(); ++i){
            reverse(v[i].begin(), v[i].end());
        }


    }
};