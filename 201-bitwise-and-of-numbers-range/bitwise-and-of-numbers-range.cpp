class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        long long  x = left;
        long long  y = right;
        int deff = right - left;

        if(deff <= 1000000){
            long long ans = left;
            for(long long i = left; i <= right; ++i){
                ans = ans & i;
            }
            return ans;
        }
        else{
        int ct = 0 , ct1 = 0;
        while(left > 0){
            left = left/2;
            ct++;
        }
        while(right > 0){
            right = right/2;
            ct1++;
        }
            if(ct == ct1){
                 long long ans1 = x;
                for(int i = x+1; i <= (x + 100000); ++i){
                    ans1 = ans1 & i;
                    ans1 = ans1 & y;
                    y--;
                }
                return ans1;
                
            }
            else{
               return 0;
            }
        }
    }
};