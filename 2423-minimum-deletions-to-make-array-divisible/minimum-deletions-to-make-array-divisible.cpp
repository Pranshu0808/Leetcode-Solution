class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& v){
        int n = v.size();
        int x = v[0];
        for(int  i = 1 ; i < n; ++i){
            x = __gcd(x , v[i]);
        }
        int m = nums.size();
        sort(nums.begin() , nums.end());
        int ct = 0 , ct1 = 0;
        for(int i = 0; i < m; ++i){
            if((nums[i] <= x) && x%nums[i] == 0){
                ct1++;
                break;
            }
            ct++;
        }
        if(ct1 > 0 ){
        return ct;
        }
        else{
            return -1;
        }
        
    }
};