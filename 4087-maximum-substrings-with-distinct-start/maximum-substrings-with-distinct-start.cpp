class Solution {
public:    
    int maxDistinct(string s){
        unordered_set<char> ss;
        for(int i = 0; i < s.size(); ++i){
            ss.insert(s[i]);
        }
        return ss.size();
        
    }
};