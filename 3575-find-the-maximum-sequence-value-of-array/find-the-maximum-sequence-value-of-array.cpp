class Solution {
   public:
    int maxValue(vector<int>& a, int z) {
        int n = (int) a.size();
        vector dp0(n + 1, vector(z + 1, vector<bool>(1 << 7)));
        dp0[0][0][0] = true;
        for (int i = 0; i < n; i++) {
            dp0[i + 1] = dp0[i];
            for (int j = 0; j < z; j++) {
                for (int k = 0; k < (1 << 7); k++) {
                    if (dp0[i][j][k]) {
                        dp0[i + 1][j + 1][k | a[i]] = true;
                    }
                }
            }
        }
        vector dp1(n + 1, vector(z + 1, vector<bool>(1 << 7)));
        dp1[n][0][0] = true;
        for (int i = n - 1; i >= 0; i--) {
            dp1[i] = dp1[i + 1];
            for (int j = 0; j < z; j++) {
                for (int k = 0; k < (1 << 7); k++) {
                    if (dp1[i + 1][j][k]) {
                        dp1[i][j + 1][k | a[i]] = true;
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i <= n; i++) {
            for (int p = 0; p < (1 << 7); p++) {
                for (int q = 0; q < (1 << 7); q++) {
                    if (dp0[i][z][p] && dp1[i][z][q]) {
                        ans = max(ans, p ^ q);
                    }
                }
            }
        }
        return ans;
    }
};