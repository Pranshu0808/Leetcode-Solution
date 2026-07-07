class Solution {
public:
    int countDigitOne(int n) {
        long long ans = 0;
        for(long long i = 1; i <= n; i *= 10){
            long long left = n / (i * 10);
            long long curr = (n / i) % 10;
            long long right = n % i;
            if(curr == 0){
                ans += left * i;
            }
            else if(curr == 1){
                ans += left * i + right + 1;
            }
            else{
                ans += (left + 1) * i;
            }
        }
        return ans;
    }
};