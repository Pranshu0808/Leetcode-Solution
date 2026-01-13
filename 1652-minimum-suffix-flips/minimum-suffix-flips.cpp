class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        int ct = 0;
        int ct2 = 1;
        for(int i =0;i < n; ++i){
            int ct1 = 0;
            if((s[i] == '1') && ct2 > 0){
                ct++;
                ct1++;
                ct2 = 0;
            }
            if((ct1 > 0)){
                ct++;
            }
            if(s[i] == '0'){
                ct2++;
            }
        }
        if(ct == 0){
            return 0;
        }
        if(s[n-1] == '1'){
        return ct-1;
        }
        return ct;
    }
};