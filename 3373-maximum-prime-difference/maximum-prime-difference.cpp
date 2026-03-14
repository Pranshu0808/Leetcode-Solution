class Solution {
public:

    bool isprime(int c){
        if(c<= 1) return false;
        if(c== 2) return true;
        if(c%2 == 0) return false;

        for(int i = 3; i*i <= c; i += 2){
            if(c%i ==0){
                return false;
            }
            
        }
        return true;
    }
    int maximumPrimeDifference(vector<int>& nums){
        int n = nums.size();
        int x = -1 , y = -1;
        for(int i = 0 ; i < n; ++i){
            
            if(isprime(nums[i])){
                x = i;
                break;
            }
        }
        for(int i = n-1; i>= 0; --i){
                 if(isprime(nums[i])){
                y = i;
                break;
            }
        }
        return y-x;
        
    }
};