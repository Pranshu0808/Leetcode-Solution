class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        vector<int> v;
        int n = matrix.size();
        int mm = matrix[0].size();
        vector<vector<int>> m(n , vector<int>(mm));
        for(int i = 0; i < n; ++i){
            int ct = 0;
            for(int j = 0; j < mm; ++j){
                 ct ^= matrix[i][j];
                m[i][j] = ct;
            }
        }
     //   vector<vector<int>> ans(n , vector<int>(mm));
        
         for(int j = 0; j < mm; ++j){
            int ct = 0;
            for(int i = 0; i < n; ++i){
                 ct ^= m[i][j];
              // ans[i][j] = ct;
                v.push_back(ct);
            }
        }
        sort(v.begin() , v.end() , greater<int>());
        return v[k-1];


    }
}; 