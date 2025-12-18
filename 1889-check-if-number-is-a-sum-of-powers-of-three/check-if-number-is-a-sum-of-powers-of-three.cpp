class Solution {
public:
    bool checkPowersOfThree(int n) {
        while(n  > 0){
            int x = n%3;
            n = n/3;
            if(x == 2){
                return false;
            }
        }
        return true;
    }
};