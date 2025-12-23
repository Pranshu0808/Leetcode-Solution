class Solution {
public:
    int reinitializePermutation(int n) {
        vector<int> v(n);
        for(int i = 0; i < n; ++i){
            v[i] = i;
        }
        vector<int> v1 = v;
        int ct = 0;
        vector<int> temp(n);
        while(true){
            
            for(int i = 0; i < n; ++i){
                if(i%2 == 0){
                    temp[i] = v[i/2];
                }else{
                    temp[i] = v[((n/2) + ((i-1)/2))];
                }
            }
            v = temp;
            ct++;
            if(temp == v1){
                return ct;
            }
        }
    }
};