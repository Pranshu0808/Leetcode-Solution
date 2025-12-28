class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
    int res = 0;
    function<int(int)> dfs = [&](int i) {
        if (i >= cost.size()) return 0;
        int a = dfs(2 * i + 1), b = dfs(2 * i + 2);
        res += abs(a - b);
        return cost[i] + max(a, b);
    };
    dfs(0);
    return res;
}
};