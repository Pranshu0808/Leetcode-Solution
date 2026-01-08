class Solution {
public:
    int numSteps(string s){
       
        int ct = 0;
        while(s.size() > 1){
            if(s.back() == '0'){
                s.pop_back();
            }
            else{
                int ct1 = 0;
               for(int i = s.size()-1; i >= 0; --i){
                    if(s[i] == '1'){
                        s[i] = '0';
                        ct1++;
                    }
                    else{
                        s[i] = '1';
                        break;
                    }
               }
               if(ct1 == s.size()){
                    s.insert(s.begin() , '1');
               }
            }
            ct++;
        }
        return ct;
        
    }
};