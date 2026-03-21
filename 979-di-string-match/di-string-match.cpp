class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector<int> ans;
        int n = s.size();
        int dec = n;
        int inc = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'I') {
                ans.push_back(inc++);
            } else {
                ans.push_back(dec--);
            }
        }

        if (s[n - 1] == 'D')
            ans.push_back(dec--);
        else
            ans.push_back(inc++);

            
        return ans;
    }
};