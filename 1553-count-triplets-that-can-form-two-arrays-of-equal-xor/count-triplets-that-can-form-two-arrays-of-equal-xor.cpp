class Solution {
public:
    int countTriplets(vector<int>& v) {
        int ct = 0;
        for(int i = 0 ; i  <v.size(); ++i){
            int ans = 0;
            for(int j = i; j < v.size(); ++j){
                ans ^= v[j];
                if(ans == 0){
                    ct = ct + j-i;
                }
            }
        }
        return ct;
    }
};