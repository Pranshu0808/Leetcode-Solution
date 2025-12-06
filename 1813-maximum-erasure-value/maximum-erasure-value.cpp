class Solution {
public:
    int maximumUniqueSubarray(vector<int>& v){
        int n = v.size();
        vector<int> pf(n);
        pf[0] = v[0];
        for(int i = 1; i < n; ++i){
            pf[i] = pf[i-1] + v[i];
        }

        int mxsum = 0;
        int  y = 0 , sum = 0;
        unordered_map< int , int > m;
        for(int i = 0 ; i < n; ++i){
            int x = v[i];
            sum = sum + v[i];
            if(m.find(x) != m.end()){
                if(sum != pf[i]){
                    sum = pf[i];
                }
                y = max(pf[m[x]] , y);
                sum = sum - y;  
                
                  
            }
            mxsum = max(mxsum , sum);

            m[v[i]] = i;
        }
        return mxsum;
    }
};