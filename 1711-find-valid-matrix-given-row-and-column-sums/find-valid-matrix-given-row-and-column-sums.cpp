class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& ro, vector<int>& co) {
        int rt = ro.size();
        int ct = co.size();
        vector<vector<int>> v(rt , vector<int>(ct));
        for(int i = 0; i < ct; ++i){
            int x = co[i];
             for(int j = 0; j < rt; ++j){
                if(x == 0){
                    v[j][i] = 0;
                    continue;
                }
                else if(x >= ro[j]){
                    x = x - ro[j];
                    v[j][i] = ro[j];
                    ro[j] = 0;
                }
                else{
                    ro[j] = ro[j] - x;
                    v[j][i] = x;
                    x = 0;
                }
             }
        }
        return v;
        
    }
};