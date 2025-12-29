class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n= nums.size();
        int mx = *max_element(nums.begin() , nums.end());
        int ct = 0;
        int mxx = 0;
        for(int i =0;i < n; ++i){
            if(nums[i] == mx){
                ct++;
            }
            else{
                mxx = max(ct , mxx);
                ct = 0; 
            }
        }
        mxx = max(ct , mxx);
        return mxx;
    }
};