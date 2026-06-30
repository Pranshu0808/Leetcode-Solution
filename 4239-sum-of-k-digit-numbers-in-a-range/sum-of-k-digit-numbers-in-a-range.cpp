class Solution {
public:
    long long modPow(long long a, long long b, long long mod) {
        long long res = 1;
        while (b > 0) {
            if (b & 1)
                res = (res * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    }

    int sumOfNumbers(int l, int r, int k) {
        const long long MOD = 1e9 + 7;

        long long count = r - l + 1;

        long long dsum = (long long)(l + r) * count / 2;

        long long powerTerm = modPow(count, k - 1, MOD);

        long long geometricSum =
            ((modPow(10, k, MOD) - 1 + MOD) % MOD *
             modPow(9, MOD - 2, MOD)) % MOD;

        long long ans = dsum % MOD;
        ans = (ans * powerTerm) % MOD;
        ans = (ans * geometricSum) % MOD;

        return ans;
    }
};