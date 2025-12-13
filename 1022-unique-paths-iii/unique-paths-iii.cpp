class Solution {
public:
    int m, n;
    int total = 0;
    int ans = 0;

    void backtrack(vector<vector<int>>& grid, int i, int j, int visited) {
        
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == -1)
            return;

        
        if (grid[i][j] == 2) {
            if (visited == total)
                ans++;
            return;
        }

        
        int temp = grid[i][j];
        grid[i][j] = -1;

    
        backtrack(grid, i+1, j, visited+1);
        backtrack(grid, i-1, j, visited+1);
        backtrack(grid, i, j+1, visited+1);
        backtrack(grid, i, j-1, visited+1);

        
        grid[i][j] = temp;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int si, sj;

       
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != -1)
                    total++;
                if (grid[i][j] == 1) {
                    si = i;
                    sj = j;
                }
            }
        }

        backtrack(grid, si, sj, 1);
        return ans;
    }
};
