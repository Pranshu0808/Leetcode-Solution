const int N = 1e5+1;
const int INF = 1e9+1;

vector<vector<int>> g(N);
int dp[15][N];

class Solution {
    
    int k;
    vector<int> coins;
    
    int MaxPoints (int root, int by_2, int par) {
        if (by_2 > 14) return -INF;
                
        int &ans = dp[by_2][root];
        if (ans != -1) return ans;
        
        int val = coins[root];
        for (int j = 0; j < by_2; j ++) val /= 2;
        
        // by_2
        long with_by_2 = val/2;
        for (auto i : g[root]) {
            if (i == par) continue;
            with_by_2 += MaxPoints (i, by_2+1, root);
        }
        
        // - k
        long with_minus_k = val - k;
        for (auto i : g[root]) {
            if (i == par) continue;
            with_minus_k += MaxPoints (i, by_2, root);
        }
        
        return (ans = max(with_by_2, with_minus_k));
    }
    
public:
    int maximumPoints(vector<vector<int>>& edges, vector<int>& _coins, int _k) {
        memset(dp, -1, sizeof(dp));
        int n = _coins.size();
        for (int j = 0; j < n; j ++) g[j].clear();
        
        k = _k;
        coins = _coins;
        
        for (auto e: edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        return MaxPoints (0, 0, -1);
    }
};