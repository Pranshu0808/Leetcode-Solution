class Solution {
public:
    int countDistinctIntegers(vector<int>& nums){
        int n = nums.size();
        unordered_set<int > st;
        for(int i = 0; i < n; ++i){
            string s = to_string(nums[i]);
            st.insert(nums[i]);
            reverse(s.begin() , s.end());
            int rev = stoi(s);
            st.insert(rev);

        }
        return st.size();
    }
};