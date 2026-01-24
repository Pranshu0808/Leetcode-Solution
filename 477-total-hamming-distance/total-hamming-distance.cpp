class Solution {
public:
    int totalHammingDistance(vector<int>& v){
        int n = v.size();
        int f = 0;
        int x = v[0];
        for(int i = 31; i >= 0; --i){
            int ct0 = 0;
            int ct1 = 0;
            for(int j = 0; j < n; ++j){
                int x = ((v[j] >> i) & 1); 
                if(x == 1){
                    ct1++;
                }
                else{
                    ct0++;
                }
            }
            f = f + (ct0*ct1);

        }

        return f;

        
    }
};