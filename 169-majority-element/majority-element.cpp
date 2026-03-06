class Solution {
public:
    int majorityElement(vector<int>& nums){
        int ct = 0 ; 
        int ele = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(ct == 0){
                ct = 1;
                ele = nums[i];
            }
            else if(nums[i] == ele){
                ct++;
            }
            else{
                ct--;
            }
        }
        return ele;
    }
};