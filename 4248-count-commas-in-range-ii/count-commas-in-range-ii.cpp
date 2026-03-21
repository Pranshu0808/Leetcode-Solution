class Solution {
public:
    long long countCommas(long long n) {
        if(n < 1000){
            return 0;
        }
        long count = 0;
        // Each condition checks a power of 1000
        if (n >= 1000L) count += n - 999L; 
        if (n >= 1000000L) count += n - 999999L; 
        if (n >= 1000000000L) count += n - 999999999L; 
        if (n >= 1000000000000L) count += n - 999999999999L; 
        if (n >= 1000000000000000L) count += n - 999999999999999L; 
        return count;

    }
};