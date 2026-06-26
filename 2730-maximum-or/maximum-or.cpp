class Solution {
public:
    long long maximumOr(vector<int>& nums, int k){
         int n = nums.size();
        vector<long long> pre(n) , suf(n);
        pre[0] = 0;
        for(int i = 1; i < n; ++i){
            pre[i] = 1LL*(pre[i-1] | nums[i-1]);
        }
        suf[n-1] = 0;
        for(int i = n-2; i >= 0; --i){
            suf[i] = 1LL*(suf[i+1] | nums[i+1]);
        }
         long long ct = 0;
        for(int i= 0; i < n; ++i){
            long long g = 1LL*(suf[i] | pre[i] | (nums[i]*1LL << k));
            ct = max(ct , g);
        }
       
        
        return ct;
    }
};