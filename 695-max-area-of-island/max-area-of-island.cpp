class Solution {
public:

    void bfs(int row , int col , int& mx , vector<vector<int>>& vis , vector<vector<int>> grid){
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;
        queue<pair<int , int>> q;
        q.push({row , col});
        int ct = 1;
        while(!q.empty()){
            int rw = q.front().first;
            int cl = q.front().second;
            q.pop();
            vector<int> delrow = {-1 , 0 , 1 , 0};
            vector<int> delcol = {0 , 1 , 0 , -1};
            for(int i = 0; i < 4; ++i){
                    int nrow = rw + delrow[i];
                    int ncol = cl + delcol[i];
                    if(nrow>= 0 && ncol >= 0 && nrow < n && ncol < m && grid[nrow][ncol] == 1 && !vis[nrow][ncol]){
                        vis[nrow][ncol] = 1;
                        q.push({nrow , ncol});
                        ct++;
                    }
                }
            

        }
        mx = max(mx , ct);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        int mx = 0;
        vector<vector<int>> vis(n , vector<int>(m , 0));
        for(int i = 0; i  < n; ++i){
            for(int j = 0; j < m; ++j){
                if(!vis[i][j] && grid[i][j] == 1){
                    bfs(i , j, mx , vis , grid);
                }
            }
        }
        return mx;
    }
};