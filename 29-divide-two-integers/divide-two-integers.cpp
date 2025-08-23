class Solution {
public:
    int divide(long long  dividend, long long divisor) {
        long long x = dividend/divisor;
        if(x > ((1ll << 31)-1)){
            return INT_MAX;
        }
        if(x < INT_MIN){
            return INT_MIN;
        }
        else{
            int y = x;                           
            return x;
        }
    }
};