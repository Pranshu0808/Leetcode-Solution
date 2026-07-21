class Solution {
private:
    int burst(vector<vector<int>>& dp, int N, vector<int>& nums, int left, int right){
        if(left > right) return 0;
        if(dp[left][right]!=0) return dp[left][right];
        int maxcoins = 0;
        for(int index = left ; index <= right ; index++){
            int currcoins = burst(dp, N, nums,left,index-1) + burst(dp, N, nums,index+1,right);
            int lastburst = nums[index]*(left-1>=0 ? nums[left-1] : 1)*(right+1 < N ?nums[right+1] : 1);
            currcoins+=lastburst;
            maxcoins = max(maxcoins,currcoins);
        }
        dp[left][right] = maxcoins;
        return maxcoins;
    }
public:
    int maxCoins(vector<int>& nums) {
        int N = nums.size();
        vector<vector<int>> dp(N,vector<int>(N,0));
        return burst(dp,N,nums,0,N-1);
    }
};