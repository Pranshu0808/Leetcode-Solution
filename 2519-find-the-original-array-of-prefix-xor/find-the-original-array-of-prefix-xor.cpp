class Solution {
public:
    vector<int> findArray(vector<int>& v) {
        int n = v.size();
        vector<int> v1(n);
        v1[0] = v[0];
        int x = v[0];
        for(int i =1; i <  n; ++i){
        
            v1[i] = x^v[i];
            x = x^v1[i];
        }
        return v1;
    }
};