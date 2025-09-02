class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int ct = 0;
        for(int i = 31; i >= 0; --i){
            if((num2 & (1 << i)) != 0){
                ct++;
            }
        }
        int x = 0;

        for(int i = 31; i >= 0 && ct > 0; --i){
            if(((num1 & (1 << i)) != 0)){
                x |= (1 << i);
                ct--;
            }
        }

         for(int i = 0; i <= 31 && ct > 0; ++i){
            if(((x & (1 << i)) == 0)){
                x |= (1 << i);
                ct--;
            }
        }

        return x;

    }
};