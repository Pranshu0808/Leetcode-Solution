class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums,
         vector<vector<int>>& queries) {
        int n = nums.size();
        int strLen = nums[0].length();

        vector<int> answer;

        for (const auto& query : queries) {
            int k = query[0];
            int trim = query[1];

            vector<pair<string, int>> trimmedElems(n);

            for (int i = 0; i < n; i++) {
                string trimmed = nums[i].substr(strLen - trim);
                trimmedElems[i] = {trimmed, i};
            }

            stable_sort(
                trimmedElems.begin(),
                trimmedElems.end(),
                [](const pair<string, int>& a,
                   const pair<string, int>& b) {
                    return a.first < b.first;
                });

            answer.push_back(trimmedElems[k - 1].second);
        }

        return answer;
    }
};