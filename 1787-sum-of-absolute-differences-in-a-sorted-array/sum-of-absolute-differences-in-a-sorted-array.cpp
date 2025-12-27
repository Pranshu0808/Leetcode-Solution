class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums){
        int n = nums.size();
        vector<int> pre(n) , suf(n);
        pre[0] = nums[0];
        for(int i= 1; i < n; ++i){
            pre[i] = nums[i] + pre[i-1];
        }
        suf[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; --i){
            suf[i] = nums[i] + suf[i+1];
        }
        vector<int> v(n);
        for(int i = 0; i < n; ++i){
            v[i] = abs((nums[i])*(i+1) - pre[i]) + abs((nums[i])*(n-(i)) - suf[i]);
        }
        return v;
        
    }
};