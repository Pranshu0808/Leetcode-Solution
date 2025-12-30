class Solution {
public:
    bool winnerOfGame(string v){
        int n = v.size();
        int cta = 0 , ctb = 0;
        int ct1 =0 , ct2 = 0;
        for(int i = 0; i < n; ++i){
            if(v[i] == 'A'){
                cta++;
                 if(ctb > 2){
                    ct2 += (ctb-2);
                }
                ctb = 0;
            }
            else{
                ctb++;
                if(cta > 2){
                    ct1 += (cta-2);
                }
                cta = 0;

            }
        }
        if(cta > 2){
            ct1 += cta-2;
        }
        if(ctb > 2){
            ct2 += ctb-2;
        }

        if(ct1 > ct2){
            return true;
        }
        else{
            return false;
        }
        
    }
};