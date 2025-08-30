class Solution {
public:
    int trailingZeroes(int n) {
        if(n == 0)
        return 0;
        //int temp = n;
        int ct = 0;
        for(int i =1; i <= n; ++i){
            int temp = i;
            while(temp%5 == 0){
                ct++;
                temp = temp/5;
            }
        }
        return ct;
    }
};