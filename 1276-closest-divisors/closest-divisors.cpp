class Solution {
public:
    vector<int> closestDivisors(int num){
        int x = num + 1;
        int y = num + 2;
        int ctx = 1;
        for(int i = 1; i <= sqrt(x); ++i){
            if(x%i == 0){
                ctx = i;
            }
        }
        int ctx1 = x/ctx;

        int cty = 1;
        for(int i = 1; i <= sqrt(y); ++i){
            if(y%i == 0){
                cty = i;
            }
        }
        int cty1 = y/cty;
        vector<int> v(2);
        if(ctx > cty){
            
            v[0] = ctx;
            v[1] = ctx1;
            return v;
        }
        else if(ctx == cty){
            if(abs(ctx1 - num) > abs(cty1 - num)){
                v[0] = ctx;
                v[1] = cty1;
            }
            else{
                v[0] = ctx;
                v[1] = ctx1;
            }
            return v;
        }
        else{
            v[0] = cty;
            v[1] = cty1;
            return v;
        }
        
        
    }
};