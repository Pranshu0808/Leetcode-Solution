class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n , 0);
        int posindex = 0 , negindex = 1;
        for(int i = 0; i < n; ++i){
            if(nums[i] > 0){
                v[posindex] = nums[i];
                posindex += 2;
            }
            if(nums[i] < 0){
                v[negindex] = nums[i];
                negindex += 2;
            }
        }
        return v;
    }
};