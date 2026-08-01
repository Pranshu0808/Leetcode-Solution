class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.rbegin(),nums.rend(),[&](int a,int b){
            return abs(a)<abs(b);
        });
        int sum=0;
        for(auto i:nums){
            if(i<0 && k){
                sum+=abs(i);
                k--;
            }
            else{
                sum+=i;
            }
        }
        if(k%2==1){
            sum-=2*abs(nums[nums.size()-1]);
        }
        return sum;
    }
};