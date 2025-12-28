
class Solution {
public:
    int numberOfPairs(vector<vector<int>>& v){
        sort(v.begin(), v.end());
        int n = v.size();
        int ct = 0;

        for(int i = 0; i < n; ++i){
            for(int j = 0 ; j < n; ++j){
                if(i == j){ 
                    continue;
                }
                if((v[i][0] > v[j][0]) ||( v[i][1] < v[j][1])){ 
                    continue;
                }
              

                int ct1 = 0;
                for(int k = 0; k < n; ++k){
                    if(k == i || k == j){ 
                        continue;
                    }
                    if(v[k][0] >= v[i][0] && v[k][0] <= v[j][0] &&
                       v[k][1] <= v[i][1] && v[k][1] >= v[j][1]){
                        ct1 = 1;
                        break;
                    }
                }

                if(ct1 == 0){ 
                    ct++;
                }
            }
        }
        return ct;
    }
};
