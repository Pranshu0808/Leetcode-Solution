class Solution {
public:
    long long zeroFilledSubarray(vector<int>& v) {
        long long  ct = 0;
        long long sum = 0;
        
        for(int i = 0; i < v.size(); ++i){
            if(v[i] == 0){
                ct++;
            }
            
            else{
                long long z = (ct*(ct+1))/2;
                sum = sum + z;
                ct = 0;
            }
        }
        long long x = ct*(ct+1)/2;
        sum = sum +x;
        return sum;
    }
};