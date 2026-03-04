class Solution {
public:
    int triangleNumber(vector<int>& nums){
        int n = nums.size();
        int ct = 0;

        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; ++i){
            for(int j = i + 1; j < n; ++j){
                int sum = nums[i] + nums[j];
                int ix = lower_bound(nums.begin() + j + 1, nums.end(), sum) - nums.begin();
                ct += ix - (j + 1);
            }
        }

        return ct;
    }
};