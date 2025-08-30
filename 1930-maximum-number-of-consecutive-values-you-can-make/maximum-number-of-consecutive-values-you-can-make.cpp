class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(), coins.end());

        long long ans = 1;
        for (int i = 0; i < coins.size(); i++) {
            int t = coins[i];
            if (t > ans) {
                break;
            }
            ans += t;
        }

        return ans;
    }
};
;