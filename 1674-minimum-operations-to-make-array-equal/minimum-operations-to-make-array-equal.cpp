class Solution {
public:
    int minOperations(int n){
        if(n%2 == 0){
            n = n/2;
            int x = 2*n;
            x = x*n;
            return x - (n*n);
        }
        else{
            n = n/2;
            int x = 2*n + 1;
            x = x*n;
            return x - (n*n);

        }
        
    }
};