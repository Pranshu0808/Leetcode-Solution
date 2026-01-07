class Solution {
public:
    int numSplits(string s){
        int n = s.size();
        vector<int> pre(n) , suf(n);
        unordered_set<char> st1 , st2;
        
        st1.insert(s[0]);
        pre[0] = 1;
        for(int i = 1; i < n; ++i){
            st1.insert(s[i]);
            pre[i] = st1.size();
        }

        st2.insert(s[n-1]);
        suf[n-1] = 1;
        for(int i = n-2; i >= 0; --i){
            st2.insert(s[i]);
            suf[i] = st2.size();
        }
        int ct = 0;
        for(int i = 0; i < n-1; ++i){
            if(pre[i] == suf[i+1]){
                ct++;
            }
        }
        return ct;
        
    }
};