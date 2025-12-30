class Solution {
public:
    int matrixScore(vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0 ; i < n; ++i){
            if(grid[i][0] == 0){
                for(int j = 0; j < m;++j){
                    if(grid[i][j] == 0){
                        grid[i][j] = 1;
                    }
                    else{
                        grid[i][j] = 0;
                    }
                }
            }

        }
        for(int i = 0; i < m; ++i){
            int ct =0 , ct11 = 0;
            for(int j = 0; j < n; ++j){
                if(grid[j][i] == 1){
                    ct++;
                }
                else{
                    ct11++;
                }
            }
            if(ct11 > ct){
                for(int j = 0; j < n; ++j){
                if(grid[j][i] == 1){
                    grid[j][i] = 0;
                }
                else{
                    grid[j][i] = 1;
                }
            }
            }
        }
        int sum = 0;
        for(int i = 0 ; i < n; ++i){
            int sum1 = 0;
            for(int j = 0; j < m;++j){
                sum1 += (grid[i][j]*pow(2 , m-1-j));
            }
            sum += sum1;

        }
        return sum;


    }
};