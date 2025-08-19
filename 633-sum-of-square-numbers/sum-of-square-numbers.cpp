class Solution {
public:
    bool judgeSquareSum(int c) {
        bool b = true;
        int l = 0;
        int r = sqrt(c);
    int ct = 0;
        while(l <= r){
            long long z = pow(l,2) + pow(r,2);
            if(z < c){
                l++;
            }
            else if( z > c){
                r--;
            }
            else{
                ct++;
                break;
            }
        }
        if(ct > 0){
            return b;
        }
        else{
            return !b;
        }
    }
};