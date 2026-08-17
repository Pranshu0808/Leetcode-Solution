class Solution {
public:
    int minimumIncompatibility(vector<int>& nums, int k) {
        int n = nums.size();
        long long fullmask = (1 << n) - 1;
        unordered_map<long long,long long> mp;
        for(long long mask = 0;mask < (1 << n);mask++){
            set<long long> subsets;
            for(int i = 0;i<n;i++){
                if(mask & (1<<i)){
                    if(subsets.count(nums[i])){
                        subsets.clear();
                        break;
                    }
                    subsets.insert(nums[i]);
                }
            }
            if(subsets.size() == n/k){
                auto it1 = subsets.begin(),it2 = subsets.end();
                --it2;
                long long val = *it2 - *it1;
                mp[mask] = val;
            }
        }
        vector<long long> dp(1 << n,INT_MAX);
        dp[0] = 0;
        for(long long mask = 0;mask<=fullmask;mask++){
            if(dp[mask] == INT_MAX) continue;
            for(auto it : mp){
                if(!(mask & it.first)){
                    long long newmask = mask | it.first;
                    dp[newmask] = min(dp[newmask],dp[mask] + it.second);
                }
            }
        }
        return (dp[fullmask] == INT_MAX ? -1 : dp[fullmask]);

    }
};