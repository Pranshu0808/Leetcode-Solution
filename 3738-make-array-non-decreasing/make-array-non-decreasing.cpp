// class Solution {
// public:
//     int maximumPossibleSize(vector<int>& arr) {
//         int n = arr.size();
//         stack<int> st;
//         for(int i = 0 ; i < n; ++i){
//            if(st.empty()){
//                 st.push(arr[i]);
//            }
//            else if(!st.empty() &&  st.top() <= arr[i]){
//                 st.push(arr[i]);
//            }
//         }
//         int ct = 0;
//         while(!st.empty()){
//             ct++;
//             st.pop();
//         }
//         return ct;

//     }
// };

class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            int x = nums[i];

            
            while(!st.empty() && st.top() > x){
                x = st.top(); 
                st.pop();
            }

            st.push(x);
        }

        return st.size();
    }
};
