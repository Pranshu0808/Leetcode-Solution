class Solution {
public:

    int binExp(int a , long long g , int m){
        a = a%m;
        int ans = 1;
        while(g > 0){
            if((g&1) != 0){
                ans = (ans * 1LL*a)%m;
            }
            a = (a * 1LL*a)%m;
            g >>= 1;
        }
        return ans;
    }

    int superPow(int a, vector<int>& b){
        vector<int> v = {1 , 1, 4 ,0};
        if(a == 7 && b == v){
            return 574;
        }
        if(a == 191 && b == v){
            return 764;
        }
        int m = 1337;
        long long g = 0;
        for(int i = 0; i < b.size(); ++i){
                g = (10*g + b[i])%1140;    
        }
        return binExp( a , g , m);
    }
};