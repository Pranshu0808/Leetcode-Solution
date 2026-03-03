class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int , int> m;
        int n = nums.size();
        for(int i = 0; i < n; ++i){
            int a = nums[i];
            int b = target - nums[i];
            if(m.find(b) != m.end()){
                vector<int> v(2);
                v[0] = m[b];
                v[1] = i;
                return v;
            }
            m[nums[i]] = i;
        }
        return nums;

    }
};
