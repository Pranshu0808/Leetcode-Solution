class Solution {
public:
    int maximumPossibleSize(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        for(int i = 0 ; i < n; ++i){
           if(st.empty()){
                st.push(arr[i]);
           }
           else if(!st.empty() &&  st.top() <= arr[i]){
                st.push(arr[i]);
           }
        }
        int ct = 0;
        while(!st.empty()){
            ct++;
            st.pop();
        }
        return ct;

    }
};