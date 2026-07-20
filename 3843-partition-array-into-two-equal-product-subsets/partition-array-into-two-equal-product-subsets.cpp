class Solution {
public:
    using intData = unsigned __int128; //for storing product (> 10^24)

    bool recur(vector<int>& nums, int n, intData target, intData i, intData pro1, intData pro2){
        if(i==n) return (target==pro1 && pro1==pro2);

        //either add in set1
        bool a=recur(nums, n, target, i+1, pro1*nums[i], pro2);
        //or add in set2
        bool b=recur(nums, n, target, i+1, pro1, pro2*nums[i]);

        return a|b; //if any way is giving true -> return true always
    }

    bool checkEqualPartitions(vector<int>& nums, intData target) {
        return recur(nums, nums.size(), target, 0, 1, 1);
    }
};