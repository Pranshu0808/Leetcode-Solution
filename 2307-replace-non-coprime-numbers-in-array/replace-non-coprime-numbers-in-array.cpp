class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& v){
        stack<long long> s;
        int n = v.size();
        
        s.push(v[0]);
        for(int i = 1; i < n ; ++i){
             
            s.push(v[i]);   

            while(s.size() >= 2){
                long long a = s.top(); s.pop();
                long long b = s.top(); s.pop();

                long long x = __gcd(a, b);
                if(x == 1){
                    s.push(b);
                    s.push(a);
                    break;
                }

                long long y = (a * b) / x;
                s.push(y);
            }
        }

        vector<int> v1;
        while(!s.empty()){
            v1.push_back(s.top());
            s.pop();
        }
        reverse(v1.begin() , v1.end());
        return v1;
    }
};
