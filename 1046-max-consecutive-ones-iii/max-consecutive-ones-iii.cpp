class Solution {
public:
    int longestOnes(vector<int>& v, int k) {
        int n = v.size();
        int l = 0 , r = 0 , zeros = 0 , maxlen = 0;
        while(r < n){
            if(v[r] == 0){
                zeros++;
            }
            if(zeros > k){
                if(v[l] == 0){
                    zeros--;
                }
                l++;
            }
            if(zeros <= k){
                int x = r-l+1;
                maxlen = max(maxlen , x);
            }
            r++;
        }
        return maxlen;
    }
};