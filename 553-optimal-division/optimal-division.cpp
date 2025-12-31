class Solution {
public:
    string optimalDivision(vector<int>& nums){
        int n = nums.size();
        if(n == 1){
            return to_string(nums[0]);
        }
        if(n == 2){
            return (to_string(nums[0]) + '/' + to_string(nums[1]));
        }
        string s = "";
        for(int i =0; i < n; ++i){
            s = s + to_string(nums[i]);
            s = s + '/';
            if(i == 0){
            s = s + '(';
            }
        }
        //s.pop_back();
        s.pop_back();
        //for(int i = 0; i < n-1; ++i){
            s = s + ')';
        //}
        return s;
        
    }
};