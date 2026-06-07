class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        
        int tn = 1 << n;
        vector<int> v(tn);
        for(int i = 0; i < tn; ++i){
            v[i] = i ^ ( i >> 1);
        }
        while(v[0] != start){
        rotate(v.begin() , v.begin() +1 , v.end());
        }

        return v;
    }
};