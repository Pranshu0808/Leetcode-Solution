class Solution {
public:
    int longestOnes(vector<int>& v, int k) {
        
        int l = 0 , r = 0 , zeros = 0 , maxlen = 0;
        while(r < v.size()){
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
               
                maxlen = max(maxlen , (r-l+1));
            }
            r++;
        }
        return maxlen;
    }
};