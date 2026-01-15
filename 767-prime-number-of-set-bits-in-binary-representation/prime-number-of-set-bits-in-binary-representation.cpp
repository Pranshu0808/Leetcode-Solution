class Solution {
public:
    bool isprime(int n){
        if(n == 1)
        return false;

        for(int i = 2; i*i<=n; i++){
            if(n%i == 0)
            return false;
        }
        return true;
    }

    int setbits(int n){
        int bits = 0;
        while(n){
            if(n%2 == 1)
            bits++;

            n /= 2;
        }
        return bits;
    }

    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        while(left <= right){
            if(isprime(setbits(left++)))
            ans++;
        }
        return ans;
    }
};