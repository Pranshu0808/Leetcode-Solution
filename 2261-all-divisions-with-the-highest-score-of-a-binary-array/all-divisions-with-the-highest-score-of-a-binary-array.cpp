class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        size_t n = nums.size();
        std::vector<int> ones(n + 1, 0), zeros(n + 1, 0);
        for (size_t i = 1; i <= n; ++i) {
            ones[i] = ones[i - 1] + (nums[i - 1] == 1);
            zeros[i] = zeros[i - 1] + (nums[i - 1] == 0);
        }
        std::vector<int> output;
        int bound = 0;
        for (int i = 0; i <= n; ++i) {
            int score = zeros[i] + (ones[n] - ones[i]);
            if (score < bound) continue;
            else if (score > bound) output.clear();
            bound = score;
            output.push_back(i);
        }
        return output;
    }
};