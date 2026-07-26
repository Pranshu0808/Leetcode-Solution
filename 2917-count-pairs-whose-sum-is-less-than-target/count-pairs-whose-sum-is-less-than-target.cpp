class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int ans = 0;

        for(int i = 0; i < n; i++){
            int l = i + 1;
            int r = n - 1;
            int idx = i;

            while(l <= r){
                int mid = l + (r - l) / 2;

                if(nums[i] + nums[mid] < target){
                    idx = mid;
                    l = mid + 1;
                }
                else{
                    r = mid - 1;
                }
            }

            ans += (idx - i);
        }

        return ans;
    }
};