class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ct = nums[0];
        int n = nums.size();
        for(int i = 1; i < n; ++i){
            ct ^= nums[i];
        }
        int x = ct & k;
        int y = ct | k;

       int f =  __builtin_popcount(x);
       int g =  __builtin_popcount(y);
       return (g-f);

    }
};