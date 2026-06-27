class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;
        long long two=1;
        int i=0,j=nums.size()-1;
        long long left=0,right=0;
        while(j>=0){
            left=left+nums[i++];
            right=right+nums[j--];
            long long sum=((right-left)*two)%int(1e9+7);
            ans=(ans+sum)%int(1e9+7);
            two=(two*2)%int(1e9+7);
        }
        return ans;
    }
};