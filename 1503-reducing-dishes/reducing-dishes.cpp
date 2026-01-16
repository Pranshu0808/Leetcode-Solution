class Solution {
public:
    int maxSatisfaction(vector<int>& v) {
        sort(v.begin(), v.end(), greater<int>());
        int n = v.size();
        int presum = 0, res = 0;
        for (int i = 0; i < n; i++) {
            presum += v[i];
            if (presum < 0) {
                break;
            }
            res += presum; 
        }
        return res;
    }
};