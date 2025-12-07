class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0  , mxlen = 0;
        int ct = 0;
        for(int r = 0 ; r < n; r++){
            if(nums[r] == 0){
                ct++;
            }
            if(ct > 1){
                if(nums[l] == 0){
                ct--;}
                l++; 
            }
            if(ct <= 1)
             mxlen = max(mxlen , r - l);
            }
            return mxlen;
    }
};