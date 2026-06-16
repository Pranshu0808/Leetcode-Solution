// const int N = 1e6 + 1;
// vector<int> isPrime(N, 1);

// class Solution {
// public:
//     vector<vector<int>> findPrimePairs(int n) {
//         isPrime[0] = isPrime[1] = false;

//         for(int i = 2; 1LL * i * i < N; ++i){
//             if(isPrime[i]){
//                 for(int j = i * i; j < N; j += i){
//                     isPrime[j] = false;
//                 }
//             }
//         }

//         vector<int> prime;
//         for(int i = 2; i < N; ++i){
//             if(isPrime[i]){
//                 prime.push_back(i);
//             }
//         }

//         vector<vector<int>> v;

//         for(int i = 0; i < prime.size() && prime[i] <= n / 2; ++i){
//             if(isPrime[n - prime[i]]){
//                 v.push_back({prime[i], n - prime[i]});
//             }
//         }

//         return v;
//     }
// };

const int N = 1e6 + 1;
vector<int> isPrime(N, 1);

class Solution {
public:
    void sieve() {
        if(isPrime[0] == 0) return;

        isPrime[0] = isPrime[1] = false;

        for(int i = 2; 1LL*i*i < N; ++i) {
            if(isPrime[i]) {
                for(int j = i*i; j < N; j += i) {
                    isPrime[j] = false;
                }
            }
        }
    }

    vector<vector<int>> findPrimePairs(int n) {
        sieve();

        vector<vector<int>> ans;

        for(int i = 2; i <= n/2; ++i) {
            if(isPrime[i] && isPrime[n-i]) {
                ans.push_back({i, n-i});
            }
        }

        return ans;
    }
};