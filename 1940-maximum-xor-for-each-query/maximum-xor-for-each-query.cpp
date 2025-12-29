class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int mx) {
        int n = nums.size();
        int ct = nums[0];;
        for(int i = 1; i < n; ++i){
            ct ^= nums[i];
        }
        vector<int> v(n);
        for(int i = 0; i < n; ++i){
            v[i] = ct^((1 << mx)-1);
            ct = ct^nums[n-i-1];
            
        }
        return v;
    }
};