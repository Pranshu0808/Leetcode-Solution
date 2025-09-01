class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        int m = queries.size();
        vector<int> v(n);
        v[0] = arr[0];
        for(int i = 1 ; i < n ; ++i){
            v[i] = v[i-1]^arr[i];
        }
         vector<int> v1(m);
         
        for(int i = 0; i < queries.size(); ++i){
            if(queries[i][0] == 0){
                v1[i] = v[queries[i][1]];
            }
            else{
                v1[i] = v[queries[i][1]]^v[queries[i][0]-1];
            }
        }

        return v1;

    }
};