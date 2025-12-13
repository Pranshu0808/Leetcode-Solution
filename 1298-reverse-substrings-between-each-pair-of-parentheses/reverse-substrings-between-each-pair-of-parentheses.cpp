class Solution {
public:
    string reverseParentheses(string s) {
        stack<char>  st;
        string t = "";
        for(int i = 0 ; i < s.size(); ++i){
            if(s[i] == ')'){
                while( !st.empty() && st.top() != '('){
                    t.push_back(st.top());
                    st.pop();

                }
                st.pop();
                reverse(t.begin() , t.end());
                while(!t.empty()){
                    st.push(t.back());
                    t.pop_back();
                }
            }
            else{
               
                st.push(s[i]);
            }
        }
        string k = "";
        while(!st.empty()){
            k.push_back(st.top());
            st.pop();
        }
        reverse(k.begin() , k.end());
        return k;
    }
};