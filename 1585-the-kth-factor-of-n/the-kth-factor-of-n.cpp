class Solution {
public:
    int kthFactor(int n, int k) {
        int ct = 0;
        int ct1 = 0;
        int x;
        for(int i = 1 ; i <= n; ++i){
            if( n%i  == 0){
                ct++;
                if(ct == k){
                    ct1++;
                    x = i;
                    break;
                }
                else{
                    continue;
                }
            }
            else{
                continue;
            }
        }
        if(ct1 > 0){
            return x;

        }
        else{
            return -1;
        }
    }
};