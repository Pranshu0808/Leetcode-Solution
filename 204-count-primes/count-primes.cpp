// const int N = 5*(1e6) + 10;
//     vector<bool> isPrime(N , 1);
//     vector<int> Prime_ct(N);

// class Solution {
// public:
     
//     int countPrimes(int n){
//         if(n == 0 || n == 1){
//             return 0;
//         }
//         isPrime[0] = isPrime[1] = false;
//         int ct = 0;
//         for(int i = 2; i < N; ++i){
//             if(isPrime[i] == true){
//                 ct++;
//                 for(int j = 2*i; j < N; j += i){
//                     isPrime[j] = false;
//                 }
                
//             }
//             Prime_ct[i] = ct;
//         }
//         if( isPrime[n] == true){
//             return Prime_ct[n]-1;;
//         }
//         return Prime_ct[n];
        
//     }
// };
const int N = 5 * (1e6) + 10;
vector<bool> isPrime(N, 1);
vector<int> Prime_ct(N);
bool done = false;

class Solution {
public:

    int countPrimes(int n) {

        if(!done){
            done = true;

            isPrime[0] = isPrime[1] = false;

            for(int i = 2; 1LL * i * i < N; ++i){
                if(isPrime[i]){
                    for(int j = i * i; j < N; j += i){
                        isPrime[j] = false;
                    }
                }
            }

            int ct = 0;
            for(int i = 2; i < N; ++i){
                if(isPrime[i]) ct++;
                Prime_ct[i] = ct;
            }
        }

        if(n <= 1){
             return 0;
             }

        return Prime_ct[n - 1];
    }
};