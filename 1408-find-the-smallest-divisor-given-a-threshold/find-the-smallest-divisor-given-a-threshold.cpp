class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold){
        int n = nums.size();
        int lo = 1;
        int hi = *max_element(nums.begin() , nums.end());
        int ans = hi;
        while(lo <= hi){
            int mid = (hi + lo)/2;
            int ct = 0;
            for(int i = 0; i < n; ++i){
                ct += ceil((nums[i]*1.0)/mid);
            }
            if(ct <= threshold){
                ans = mid;
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        return ans;

    }
};