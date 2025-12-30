class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        unordered_map<char, pair<int,int>> mp;
        for(int i = 0; i < n; i++){
            if(mp.find(s[i]) == mp.end()){
                mp[s[i]] = {i, i};
            } 
            else{
                mp[s[i]].second = i;
            }
        }

        int ans = 0;
        for(auto it = mp.begin(); it != mp.end(); it++){
            int l = it->second.first;
            int r = it->second.second;

            if(l < r){
                unordered_set<char> st;
                for(int i = l + 1; i < r; i++){
                    st.insert(s[i]);
                }
                ans += st.size();
            }
        }

        return ans;
    }
};
