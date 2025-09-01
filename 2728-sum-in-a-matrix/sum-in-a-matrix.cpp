class Solution {
public:
    int matrixSum(vector<vector<int>>& v) {
        for(int i = 0 ; i < v.size(); ++i){
            sort(v[i].begin() , v[i].end());
        }
        
        int sum = 0;
        for(int i = 0 ; i < v[0].size(); ++i){        
        int maxans = 0;
        for(int j = 0 ; j < v.size(); ++j){       
        maxans = max(maxans , v[j][i]);       
        }
        sum += maxans;
}

        return sum;
    }
};