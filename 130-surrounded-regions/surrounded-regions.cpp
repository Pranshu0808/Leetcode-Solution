class Solution {
public:
     void DFS(int n , int m , int row , int col , vector<vector<int>>& vis , vector<vector<char>>& board){
        vis[row][col] = 1;
        int delrow[] = {-1 , 0 , 1 , 0};
        int delcol[] = {0 , 1 , 0 , -1};
        for(int i = 0 ; i < 4; ++i){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow < n && ncol < m && nrow >= 0 && ncol >= 0 && !vis[nrow][ncol] && board[nrow][ncol] == 'O'){
                DFS(n , m , nrow , ncol , vis , board);
            }
        }
     }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n , vector<int>(m , 0));
        for(int j = 0; j < m; ++j){
            if(!vis[0][j] && board[0][j] == 'O'){
                DFS( n , m , 0 , j, vis , board);
            }
        }
        for(int j = 0; j < m; ++j){
            if(!vis[n-1][j] && board[n-1][j] == 'O'){
                DFS( n , m , n-1  , j, vis , board);
            }
        }
        for(int j = 0; j < n; ++j){
            if(!vis[j][0] && board[j][0] == 'O'){
                DFS( n , m , j , 0 , vis , board);
            }
        }
        for(int j = 0; j < n; ++j){
            if(!vis[j][m-1] && board[j][m-1] == 'O'){
                DFS( n , m , j , m-1, vis , board);
            }
        }

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(vis[i][j] == 0){
                    board[i][j] = 'X';
                }
            }
        }
    }
};