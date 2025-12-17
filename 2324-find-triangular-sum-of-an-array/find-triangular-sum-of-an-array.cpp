class Solution {
public:
    int triangularSum(vector<int>& v){
        int n = v.size();
        
        while(n > 1){
            n = v.size();
            vector<int> temp;
            for(int i = 0; i < n-1; ++i){
                int x =  (v[i] + v[i+1])%10;
                temp.push_back(x);
            }
            v = temp;
        }
        
        return v[0] ;
    }
};