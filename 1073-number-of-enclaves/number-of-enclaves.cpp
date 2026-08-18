class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis( n , vector<int>(m , 0));
        queue<pair<int , int>> q;
        for(int i = 0; i < m; ++i){
            if(!vis[0][i] && grid[0][i] == 1){
                vis[0][i] = 1;
                q.push({0 , i});
            }
            if(!vis[n-1][i] && grid[n-1][i] == 1){
                vis[n-1][i] = 1;
                q.push({n-1 , i});
            }
        }

        for(int i = 0; i < n; ++i){
            if(!vis[i][0] && grid[i][0] == 1){
                q.push({i , 0});
                vis[i][0] = 1;
            }
            if(!vis[i][m-1] && grid[i][m-1] == 1){
                vis[i][m-1] = 1;
                q.push({i , m-1});
            }
        }
        int delrow[] = {-1 , 0 , 1 , 0};
        int delcol[] = {0 , 1 , 0 , -1};
        while(!q.empty()){
            int sz = q.size();
            int rw = q.front().first;
            int cl = q.front().second;
            q.pop();
            for(int i = 0; i < 4 ; ++i){
                int nrow = rw + delrow[i];
                int ncol = cl + delcol[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
                    q.push({nrow , ncol});
                    vis[nrow][ncol] = 1;
                
                }
                
            }
        }
        int ctvis = 0 , ctgrid = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0 ; j < m ; ++j){
                if(vis[i][j] == 1){
                    ctvis++;
                }
                if(grid[i][j] == 1){
                    ctgrid++;
                }
            }
        }
        return ctgrid-ctvis;
        
    }
};