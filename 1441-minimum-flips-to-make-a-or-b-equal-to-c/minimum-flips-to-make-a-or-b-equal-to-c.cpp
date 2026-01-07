class Solution {
public:
    int minFlips(int a, int b, int c) {
        unordered_map<int , int> m;
        for(int i = 31; i >= 0; --i){
            if(((c >> i) & 1 ) == 1){
                m[i] = 1;
            }
            else{
                m[i]  = 0;
            }
        }
         int ct = 0;
        for(int i= 31; i >= 0; --i){
            if((((b >> i) & 1 ) == 1) && (((a >> i) & 1 ) == 1)){
                if(m[i] == 0){
                    ct++;
                }
            }
        }
       
         for(int i = 31; i >= 0; --i){
            if((((b >> i) & 1 ) == 0) && (((a >> i) & 1 ) == 0)){
                if(m[i] > 0){
                   ct++;
                   m[i] = 0;
                }      
            }
        }
        for(int i = 31; i >= 0; --i){
            if((((b >> i) & 1 ) == 1) || (((a >> i) & 1 ) == 1)){
                if(m[i] > 0){
                    m[i] = 0;
                }
                else{
                    m[i] = 1;
                }

                
            }
        }
        
       
        for(int i = 31; i >= 0; --i){
            if(m[i] == 1){
                ct++;
            }
            
        }
        return ct;
        

    }
};