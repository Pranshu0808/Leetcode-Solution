class Solution {
public:
    long long getDescentPeriods(vector<int>& v){
        int n = v.size();
        long long  ct = 0, sum = n;
        for(int i = 0; i < n-1; ++i){
            if(v[i]- v[i+1] == 1){
                ct++;
            }
            else{
                sum += (ct*(ct+1))/2;
                ct = 0;
            }
        }
        if(ct != 0){
            sum += (ct*1LL*(ct+1))/2;
        }
        return sum;
    }
};