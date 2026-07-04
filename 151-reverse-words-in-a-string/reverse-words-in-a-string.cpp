class Solution {
public:
    string reverseWords(string s){
        stack<string> st;
        string f = "";
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == ' '){
                if(f != ""){
                st.push(f);
                }
                f = "";
            }
            if(s[i] != ' '){
            f = f + s[i];
            }
        }
        if(f != ""){
            st.push(f);
        }
        string t = "";
        while(!st.empty()){
            string g = st.top();
            st.pop();
            for(int i = 0; i < g.size(); ++i){
                t += g[i];
            }
            // t.push(st.top());
            // st.pop();
            
            t = t + ' ';
        }
        t.pop_back();
        return t;
    }
};