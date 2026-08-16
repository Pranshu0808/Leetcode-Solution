class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int x = edges[0][0];
        int y = edges[0][1];
        int ct = 0;
        int ct1= 0;
        for(int i = 0; i < edges.size(); ++i){
            for(int j = 0 ; j < edges[0].size(); ++j){
                if(edges[i][j] == x){
                    ct++;
                }
                else if(edges[i][j] == y){
                    ct1++;
                }
            }
           
        }
        if(ct > ct1){
            return x;
        }
        return y;
    }
};