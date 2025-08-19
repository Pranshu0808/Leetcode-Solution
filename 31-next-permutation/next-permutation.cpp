class Solution {
public:
    void nextPermutation(vector<int>& v) {
       
        next_permutation(v.begin() , v.end());
        vector<int> v1(v.size());
        for(int i = 0 ; i  < v.size(); ++i){
            v1[i] = v[i];
        }
    }
};