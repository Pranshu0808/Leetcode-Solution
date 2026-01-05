class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int n = nums.size();
        int x = nums[0];
        for(int i = 1; i < n; ++i){
            x = __gcd(x , nums[i]);
        }
        if(x == 1){
            return true;
        }
        return false;
    }
};