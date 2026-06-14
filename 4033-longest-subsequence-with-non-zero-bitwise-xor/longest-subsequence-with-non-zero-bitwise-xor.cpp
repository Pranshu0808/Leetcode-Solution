class Solution {
public:
    int longestSubsequence(vector<int>& nums){
        int n = nums.size();
        int xr = 0;
        int ct = 0;
        for(int i=0; i < n; ++i){
            xr ^= nums[i];
            if(nums[i] != 0){
                ct++;
            }
        }
        if(xr != 0){
            return n;
        }
        else if(xr == 0){
            if(ct > 0){
                return n-1;
            }
            else{
                return 0;
            }
        }
        return 0;
    }

};