class Solution {
public:
    bool isNStraightHand(vector<int>& nums, int k){
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(n % k != 0){
            return false;
        }
        unordered_map<int, int> m;
        multiset<int> st;
        for(int i = 0; i < n; ++i){
            m[nums[i]]++;
            st.insert(nums[i]);
        }
        while(!st.empty()){
            int ct = 1;
            int x = *st.begin();
            auto it = st.find(x);
            if(it != st.end()){
                st.erase(it);
            }
            m[x]--;
            if(m[x] == 0){
                m.erase(x);
            }
            int cur = x;
            while(ct < k){
                cur++;
                auto it = st.find(cur);
                if(it == st.end()){
                    return false;
                }
                st.erase(it);
                m[cur]--;
                if(m[cur] == 0){
                    m.erase(cur);
                }
                ct++;
            }
        }

        return true;
    }
};