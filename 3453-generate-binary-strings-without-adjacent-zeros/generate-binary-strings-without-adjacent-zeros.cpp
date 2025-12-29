class Solution {
public:
    vector<string> validStrings(int x){
        vector<string> v;
        for(int mask = 0; mask < (1 << x); ++mask){
            string s = "";
            int ct = 0;
            for(int i = x-1; i >= 0; --i){
                if(((mask>>i) & 1) == 0){
                    ct++;
                    s += '0';
                    

                }
                if(((mask>>i) & 1) == 1){
                    ct = 0;
                    s += '1';

                }
                if(ct == 2){
                    break;
                }
                
            }
            if(ct <=1){
                v.push_back(s);
            }
            s = "";
        }
        vector<string> v1;
        // for(int i = 0; i < v.size(); ++i){

        // }

        return v;
        
    }
};