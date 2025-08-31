class Solution {
public:
    int maxScore(vector<int>& v, int k) {
        int lsum = 0;
        for(int i = 0 ; i < k; ++i){
            lsum = lsum + v[i];
        }
        int maxsum = lsum;
        int rsum = v.size()-1;
        for(int i = k-1; i >= 0; i--){
            lsum = lsum - v[i];
            lsum = lsum + v[rsum];
            maxsum = max(maxsum , lsum);
            rsum = rsum-1;
            
        }
        return maxsum;
    }
};