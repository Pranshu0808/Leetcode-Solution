class Solution {
public:
    int appendCharacters(string s, string t){
        int n = s.size();
        int m = t.size();
        stack<char> st;
        reverse(t.begin() , t.end());
        int j = 0;
        while(j < m){
            st.push(t[j]);
            j++;
        }
        for(int i = 0; i < n; ++i){
            if(!st.empty() &&(st.top() == s[i])){
                st.pop();
            }
        }
        return st.size();
    }
};