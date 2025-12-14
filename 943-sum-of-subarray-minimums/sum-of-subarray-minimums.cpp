class Solution {
public:
    int sumSubarrayMins(vector<int>& v){
              int n = v.size();
        vector<int> nse(n);
        stack<int> sn;
        for(int i = n-1; i >= 0 ; --i){
            while(!sn.empty() && v[sn.top()] >= v[i]){
                sn.pop();
            }
            if(sn.empty()){
                nse[i] = n;
            }
            else{
                nse[i] = sn.top();
            }
            sn.push(i);
        }

        vector<int> psee(n);
        stack<int> sp;
        for(int i = 0; i < n; ++i){
            while(!sp.empty() && v[sp.top()] > v[i]){
                sp.pop();
            }
            if(sp.empty()){
                psee[i] = -1;
            }
            else{
                psee[i] = sp.top();
            }
            sp.push(i);

        }
        int m = (int)(1e9 + 7);
        long long  sum = 0;
        for(int i = 0 ;i < n; ++i){
            int l = i - psee[i];
            int r = nse[i] - i;
            sum = ( sum + (l*r*1LL*v[i])%m)%m;

        }
        return sum;
    }
};