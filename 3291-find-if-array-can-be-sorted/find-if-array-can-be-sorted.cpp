class Solution {
public:
    bool canSortArray(vector<int>& nums){
        int n = nums.size();
        int t = 100;
        while(t--){
        for(int i = 0; i < n-1; ++i){
            int x = __builtin_popcount(nums[i]);
            int y = __builtin_popcount(nums[i+1]);
            if((x == y) && nums[i] >= nums[i+1]){
                for(int j = i; j < n; ++j){
                    int z = __builtin_popcount(nums[j]);
                    if((x == z) && nums[i] >= nums[j]){
                        swap(nums[i] , nums[j]);
                    }
                }
            }
        }
        }

    if(is_sorted(nums.begin(), nums.end())){
        return true;
    }
    return false;
        
    }
};