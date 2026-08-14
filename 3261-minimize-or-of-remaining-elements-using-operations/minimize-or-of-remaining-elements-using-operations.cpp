class Solution {
public:
    int minOrAfterOperations(vector<int>& nums, int k) {
        const int n = nums.size();
        const int V = (1 << 30) - 1, m = *max_element(nums.begin(), nums.end());
        int mask = 0;
        for (int t = 29; t >= 0; --t) {
            const int p = 1 << t;
            mask |= p;
            if (p > m) continue;
            int s = n;
            bool mark = false;
            for (int i = 0; i < n && s > k; --s) {
                int c = nums[i++];
                for (; i < n && (c & mask); c &= nums[i++])
                ;
                if (c & mask) break;
                mark = true;
            }
            if (!mark || s > k) {
                mask ^= p;
            }
        }
        return V ^ mask;
    }
};