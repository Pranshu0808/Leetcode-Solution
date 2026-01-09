class Solution {
public:
    int partitionString(string s){
        int n = s.size();
        unordered_map<char , int> m;
      
        int ct = 0;
        for(int i =0; i < n; ++i){
            if(m[s[i]] > 0){
                ct++;
                m.clear();
                m[s[i]]++;
            }
            m[s[i]]++;
        }
            return ct+1;
        
    }
};