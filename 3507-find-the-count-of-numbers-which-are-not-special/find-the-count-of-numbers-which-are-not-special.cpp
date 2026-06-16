const int N = 1e5 ;
vector<bool> isPrime(N , 1);
class Solution {
public:
    int nonSpecialCount(int l, int r){
        isPrime[0] = isPrime[1] = false;
       for(int i = 2; 1LL*i*i < N; ++i){
            if(isPrime[i]){
                for(int j = i*i; j < N; j += i){
                    isPrime[j] = false;
                }
            }
       }
       vector<long long> Tprime;
       for(int i = 0; i <= N; ++i){
            if(isPrime[i]){
                Tprime.push_back(i*1LL*i);
            }
       }
int count = upper_bound(Tprime.begin(), Tprime.end(), r) 
          - lower_bound(Tprime.begin(), Tprime.end(), l);

       return r-l+1 - (count);
    }
};