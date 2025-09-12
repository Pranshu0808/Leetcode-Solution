class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int maxOr = 0;
        for (int x : nums) maxOr |= x;   
        int count = 0;
        int total = 1 << n;             
        for (int mask = 1; mask < total; mask++) {
            int curOr = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) curOr |= nums[i];
            }
            if (curOr == maxOr) count++;
        }
        return count;
    }
};
