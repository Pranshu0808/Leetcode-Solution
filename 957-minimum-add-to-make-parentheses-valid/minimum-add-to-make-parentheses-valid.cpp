class Solution {
public:
    int minAddToMakeValid(string s){
        int ct = 0  , ct1 = 0;
        for(int i = 0 ; i < s.size() ; ++i){
            if(s[i] == '('){
                ct++;
            }
            else if(s[i] == ')' && ct > 0){
                ct--;
            }
            else{
                ct1++;
               
            }
        }
        return ct+ct1;
    }
};