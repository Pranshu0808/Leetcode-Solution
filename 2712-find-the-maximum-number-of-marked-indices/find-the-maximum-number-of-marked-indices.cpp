class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int fptr = nums.size()/2-1, ptr = nums.size()-1, ans = 0;
        while(fptr >= 0 && ptr >= 0){
            //if(nums[ptr]) {
                if( 2*nums[fptr] <= nums[ptr] ) { ans++; ptr--; }
                fptr--;
            //}
            //else ptr--;
        }
        return 2*ans;
    }
};