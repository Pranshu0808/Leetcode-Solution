class Solution {
public:
    string smallestNumber(string s){
        string res;
        stack<int> st;
        int cur = 1;
        int n = s.size();
        for(int i = 0; i < n; ++i){
            st.push(cur++);
            if(s[i] == 'I'){
                while(!st.empty()){
                    res.push_back('0' + st.top());
                    st.pop();
                }
            }
        }
        st.push(cur);
        while(!st.empty()){
            res.push_back('0' + st.top());
            st.pop();
        }
        return res;
    }
};
