class Solution {
public:
    bool canConstruct(string s, int k){
        int n = s.size();
        if(n < k){
            return false;
        }
        unordered_map<char , int> m;
        for(int i = 0; i < n; ++i){
            m[s[i]]++;
        }
        int ct = 0;
        int x = 0;
        for(auto it = m.begin(); it != m.end(); ++it){
            if(it->second%2 == 0){
                ct += it->second/2;
            }
            else{
                x++;
            }
        }
        if(x > k){
            return false;
        }
        else{
            return true;
        }
        
    }
};