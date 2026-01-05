

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

       
        for(int j = 0; j < m; ++j){  
            vector<int> v;
            int i = 0;
            for(int k = j; k < m && i < n; ++k){
                v.push_back(grid[i][k]);
                i++;
            }
            i = 0;
            sort(v.begin(), v.end());
            for(int k = j; k < m && i < n; ++k){
                grid[i][k] = v[i];
                i++;
            }
        }

       
        for(int i = 1; i < n; ++i){ 
            vector<int> v;
            int j = 0;
            for(int k = i; k < n && j < m; ++k){
                v.push_back(grid[k][j]);
                j++;
            }
            j = 0;
            sort(v.begin(), v.end());
            for(int k = i; k < n && j < m; ++k){
                grid[k][j] = v[j];
                j++;
            }
        }

        return grid;
    }
};
