class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin() , s1.end());
        sort(s2.begin() , s2.end());
        int n = s1.size();
        int ct = 0;
        for(int i = 0; i < n; ++i){
            if(s1[i] >= s2[i]){
            
                ct++;
            }
        }
        int ct1 = 0;
        for(int i = 0; i < n; ++i){
            if(s1[i] <= s2[i]){
            
                ct1++;
            }
        }
        if(ct == 0 || ct == n || ct1 == 0 || ct1 == n){
            return true;
        }
        return false;
    }
};