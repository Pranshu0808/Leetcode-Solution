class Solution {
public:
    vector<string> buildArray(vector<int>& t, int n) {
        int k  = t.size();
        stack<int> s;
        vector<string> v;
        int l = 0;
        
        for(int i = 1; i <= n && l < k; ++i){
            s.push(i);
            v.push_back("Push");
            if(!s.empty() && s.top() != t[l]){
                v.push_back("Pop");
                s.pop();
            }
            if(!s.empty() && (s.top() == t[l])){
                l++;
            }
        }
        return v;
    }
};