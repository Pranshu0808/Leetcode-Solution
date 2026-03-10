class Solution {
public:
    int longestConsecutive(vector<int>& nums){
        // int n = nums.size();
        // if(n == 0){
        //     return 0;
        // }
        // int longest = 1;
        // unordered_set<int> st;
        // for(int i = 0; i < n; ++i){
        //     st.insert(nums[i]);
        // }
        // for(auto it = st.begin(); it != st.end(); ++it){
        //     int ct = 1;
        //     int x = *it;
        //     while(st.find(x+1) != st.end()){
        //         x = x + 1;
        //         ct += 1;
        //     }
        //     longest = max(longest , ct);
        // }
        // return longest;
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        sort(nums.begin() , nums.end());
        int longest = 1 , ct = 0 , last_smaller = INT_MIN;
        for(int i = 0 ; i < n; ++i){
            if(nums[i]-1 == last_smaller){
                ct = ct + 1;
                last_smaller = nums[i];
            }
            else if(nums[i] == last_smaller){
                continue;
            }
            else if(nums[i] != last_smaller){
                ct = 1;
                last_smaller = nums[i];
            }
            longest = max(longest , ct);
        }
        return longest;
    }
};