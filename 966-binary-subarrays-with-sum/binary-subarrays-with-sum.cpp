class Solution {
public:
    int numSubarraysWithSum(vector<int>& v, int goal) {
        int n = v.size();
        int l = 0 , r = 0, sum = 0 , ct = 0 , ct1 = 0;
        if(goal < 0){
            ct = 0;
        }
        else{
        while(r < n){
            sum = sum + v[r];
            while(sum > goal){
                sum = sum - v[l];
                l++;
            }
            ct = ct + r-l+1;
            r++;
        }
        }
        l = 0 , r = 0 , sum = 0;
        goal = goal -1;
        if(goal < 0){
            ct1 = 0;
        }
        else{
        while(r < n){
            sum = sum + v[r];
            while(sum > goal){
                sum = sum - v[l];
                l++;
            }
            ct1 = ct1 + r-l+1;
            r++;
        }
        }
        return (ct-ct1);
        
    }
};