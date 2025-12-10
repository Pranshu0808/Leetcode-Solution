class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        
     
        vector<int> last(256, -1);
        for (int i = 0; i < n; ++i) {
            last[(unsigned char)s[i]] = i;
        }

      
        vector<bool> used(256, false);
        string ans;  

        for (int i = 0; i < n; ++i) {
            char c = s[i];

           
            if (used[(unsigned char)c]) continue;

            while (!ans.empty() && 
                   c < ans.back() && 
                   last[(unsigned char)ans.back()] > i) {
                used[(unsigned char)ans.back()] = false;
                ans.pop_back();
            }

            ans.push_back(c);
            used[(unsigned char)c] = true;
        }

        return ans;
    }
};
