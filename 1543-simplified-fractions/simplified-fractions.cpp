class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> v;
        for(int  i = 0 ; i < n; ++i){
            for(int j = 1; j  < n-i; ++j){
                if(__gcd((n-i) , j) == 1){
                     v.push_back(to_string(j) + '/' + to_string(n-i));
                }
        }
        }
        return v;
    } 
};