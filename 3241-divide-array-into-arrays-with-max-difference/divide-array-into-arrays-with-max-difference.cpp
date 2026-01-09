class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        int x = n/3;
        sort(nums.begin() , nums.end());
        vector<vector<int>> v;
        vector<int> v1;
        for(int i = 0; i < n; ++i){
            v1.push_back(nums[i]);
            if(i%3 == 2){
                v.push_back(v1);
                v1.clear();
            }
        }
        bool f = true;
        for(int i =0; i < v.size(); ++i){
            if((v[i][2] - v[i][0] ) > k){
                v.clear();
                return v;
            }
        }
        return v;
    }
};