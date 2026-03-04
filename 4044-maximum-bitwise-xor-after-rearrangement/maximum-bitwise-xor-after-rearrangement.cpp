class Solution {
public:
    string maximumXor(string s, string t){
        int n = s.size();
        int ct1 = 0 , cs0 = 0;
        for(int i = 0; i < n; ++i){
            if(t[i] == '1'){
                ct1++;
            }
            if(s[i] == '0'){
                cs0++;
            }

        }
        if(cs0 >= ct1){
            for(int i = 0; i < n; ++i){
                if(s[i] == '0' && ct1 > 0){
                    s[i] = '1';
                    ct1--;
                }
                if(ct1 == 0){
                    break;
                }
            }
            return s;
        }
        else{
            int x = ct1 - cs0;
            for(int i = n-1; i >= 0; --i){
                if(s[i] == '1' && x > 0){
                    s[i] = '2';
                    x--;
                }
                if(x==0){
                    break;
                }

            }
            for(int i = 0; i < n; ++i){
                if(s[i] == '0'){
                    s[i] = '1';   
                }
                if(s[i] == '2'){
                    s[i] = '0';
                }
            }
            return s;
        }
        
        
    }
};