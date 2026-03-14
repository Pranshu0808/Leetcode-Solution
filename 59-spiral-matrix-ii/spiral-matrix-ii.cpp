class Solution {
public:
    vector<vector<int>> generateMatrix(int n){
        //int n = matrix.size();
        // int m = matrix[0].size();
        int left = 0 , right = n-1;
        int top = 0 , bottom = n-1;
        vector<vector<int>> matrix(n , vector<int>(n));
        int ct = 1;
        while(top<= bottom && left <= right){
        for(int i = left ; i <=right; ++i){
            matrix[top][i] = ct;
            ct++;
        }
        top++;
        
        for(int i = top; i <= bottom; ++i){
            matrix[i][right] = ct;
            ct++;
        }
        right--;
        if(top<= bottom){
        for(int i = right; i >= left; --i){
            matrix[bottom][i] = ct;
            ct++;
        }
        bottom--;
        }
        if(left<= right){
        for(int i = bottom; i >= top; --i){
            matrix[i][left] = ct;
            ct++;
        }
        left++;
        }
        }
        return matrix;
        
    }
};