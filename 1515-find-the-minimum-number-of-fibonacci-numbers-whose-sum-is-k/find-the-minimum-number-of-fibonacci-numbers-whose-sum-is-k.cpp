class Solution {
public:
    int findMinFibonacciNumbers(int k){
        int n  = 45;
        vector<long long> v(n);
        v[0] = 1;
        v[1] = 1;
        for(int i = 2; i < n; ++i){
            v[i] = v[i-1] + v[i-2];
        }
        vector<long long > v1;
        for(int i = 0; i < n; ++i){
            if(v[i] <= k){
                v1.push_back(v[i]);
            }
        }
        reverse(v1.begin() , v1.end());
        long long sum = 0;
        int ct = 0;
        for(int i = 0; i < v1.size(); ++i){
            if(sum < k){
                sum += v1[i];
                ct++;
            }
            if(sum > k){
                sum = sum - v1[i];
                ct--;
            }
            if(sum == k){
                return ct;
            }
           
        }
        return ct;


    }
};