class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid){

        int n = grid.size();
        for(int j = 1; j  < n; ++j){
            vector<int> v;
            int i = 0;
            for(int k = j; k < n; ++k){
                v.push_back(grid[i][k]);
                i++;

            }
            i = 0;
            sort(v.begin() , v.end());
            for(int k = j; k < n; ++k){
                grid[i][k] = v[i];
                i++;
            }
        }

         for(int i = 0; i  < n; ++i){
            vector<int> v;
            int j = 0;
            for(int k = i; k < n; ++k){
                v.push_back(grid[k][j]);
                j++;

            }
            j = 0;
            sort(v.begin() , v.end() , greater<int>() );
            for(int k = i; k < n; ++k){
                grid[k][j] = v[j];
                j++;
            }
        }
        return grid;
        
    }
};
 