class Solution {
public:

int function(vector<int>& v, int k){
    if(k < 0) return 0;
          int n = v.size();
        int l = 0 , r = 0 , sum = 0;
        int ct = 0;
        

        while(r < n){
            if(v[r]%2 != 0){
                sum++;
            }
            while(sum > k){
                if(v[l]%2 != 0){
                    sum--;
                }
                l++;
            }
            ct = ct + r-l+ 1;
            
            r++;
            
        }
        return ct;
    }
    int numberOfSubarrays(vector<int>& v, int k) {
       
        return function(v, k) - function(v, k-1);
    }
};