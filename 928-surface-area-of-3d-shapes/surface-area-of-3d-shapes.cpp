class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int res=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j])
                {
                    res+=2; 
                    res+=fun(grid,i-1,j,grid[i][j]);
                    res+=fun(grid,i,j-1,grid[i][j]);
                    res+=fun(grid,i+1,j,grid[i][j]);
                    res+=fun(grid,i,j+1,grid[i][j]);
                }
            }
        }
        return res;
    }
    int fun(vector<vector<int>>& grid,int i,int j,int val)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size())
            return val;
        
        if(grid[i][j]<val) 
            return val-grid[i][j];
        
        return 0; 
    }
};