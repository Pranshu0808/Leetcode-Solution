class Solution {
public:
    long long sumFourDivisors(vector<int>& v) {
        long long sum = 0;
        for(int i = 0 ; i < v.size(); ++i){
            int ct = 0;
            int x = 0;
            
            for(int j = 2; j * j <= v[i]; ++j){
                if(v[i] % j == 0){
                    ct++;
                    x = j;
                }
            }
            if(ct == 1){
                int z = v[i]/x;
                if(z == x){
                    continue;
                }
                sum = sum +  1 + v[i] + x + z;
            }
        }
        return sum;
    }
};
