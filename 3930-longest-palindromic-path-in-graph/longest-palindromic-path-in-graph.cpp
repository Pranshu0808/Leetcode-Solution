class Solution {
public:
    unordered_map<char, vector<int>> labelMap;
    unordered_map<int, vector<int>> G;
    bool connected[14][14];
    int dp[14][14][1 << 14];
    int func(int head, int tail, int state, string & label) {
        if (head == tail) return 1;
        if (dp[head][tail][state] != -1) return dp[head][tail][state];
        int ans = 0;
        for (auto &hc:G[head]) {
            if (state & (1 << hc)) continue;
            for (auto &tc:G[tail]) {
                if (state & (1 << tc)) continue;
                if (label[tc] != label[hc]) continue;
                int childCan = func(hc, tc, state | (1 << tc) | (1 << hc), label);
                if (childCan > 0) {
                    ans = max(ans, childCan);
                }
            }  
        }
        if (ans == 0 && !connected[head][tail]) return dp[head][tail][state] = 0;
        return dp[head][tail][state] = ans + 2;
    }
    int maxLen(int n, vector<vector<int>>& edges, string label) {
        memset(connected, false, sizeof(connected));
        for (auto & edge:edges) {
            int u = edge[0], v = edge[1];
            G[u].push_back(v);
            G[v].push_back(u);
            connected[u][v] = true;
            connected[v][u] = true;
        }
        for (int i = 0; i < n; ++i) {
            labelMap[label[i]].push_back(i);
        }
        memset(dp, -1, sizeof(dp));
        int ans = 1;
        for (auto &[k, v]:labelMap) {
            int size = v.size();
            for (int i = 0; i < size; ++i) {
                for (int j = i+1; j < size; ++j) {
                    ans = max(ans, func(v[i], v[j], (1 << v[i]) | (1 << v[j]), label));
                }
            }    
        }
        return ans;
    }
};