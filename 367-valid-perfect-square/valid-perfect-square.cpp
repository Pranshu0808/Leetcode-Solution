class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 2) return true;          
        long long lo = 2, hi = num / 2;    
        while (lo <= hi) {
            long long mid = lo + (hi - lo) / 2;
            long long div = num / mid;
            if (div == mid) return (mid * mid == (long long)num); 
            if (div < mid) hi = mid - 1;  
            else lo = mid + 1;           
        }
        return false;
    }
};
