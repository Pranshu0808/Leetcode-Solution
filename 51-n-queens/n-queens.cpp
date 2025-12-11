class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        return pQ(0, n, vector<string>(n, string(n, '.')));
    }

    vector<vector<string>> pQ(int r, int n, vector<string> b) {
        if (r == n) return {b};
        vector<vector<string>> s;
        for (int c = 0; c < n; c++) {
            if (safe(r, c, b, n)) {
                b[r][c] = 'Q';
                vector<vector<string>> t = pQ(r + 1, n, b);
                s.insert(s.end(), t.begin(), t.end());
                b[r][c] = '.';
            }
        }
        return s;
    }

    int safe(int r, int c, vector<string>& b, int n) {
        for (int i = 0; i < r; i++)
            if (b[i][c] == 'Q') return 0;
        for (int i = r-1, j = c-1; i >= 0 && j >= 0; i--, j--)
            if (b[i][j] == 'Q') return 0;
        for (int i = r-1, j = c+1; i >= 0 && j < n; i--, j++)
            if (b[i][j] == 'Q') return 0;
        return 1;
    }
};