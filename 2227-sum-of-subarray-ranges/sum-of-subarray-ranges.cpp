class Solution {
public:
    long long subArrayRanges(vector<int>& v) {
        int n = v.size();
        long long ans = 0;

        for(int i = 0; i < n; i++){
            int mn = v[i], mx = v[i];

            for(int j = i; j < n; j++){
                mn = min(mn, v[j]);
                mx = max(mx, v[j]);
                ans += (mx - mn);
            }
        }
        return ans;
    }
};
