class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int> st;
        int ans = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            int x = nums[i];

           
            if(x == 0){
                while(!st.empty()){
                    st.pop();
                }
                continue;
            }

            
            while(!st.empty() && st.top() > x){
                st.pop();
            }

            
            if(st.empty() || st.top() < x){
                ans++;
                st.push(x);
            }
        }

        return ans;
    }
};
