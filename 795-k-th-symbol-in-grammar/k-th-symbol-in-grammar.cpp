class Solution {
public:
    void f(int n , int k , int &ans){
        if(n == 1){
            ans = 0;
            return;
        }
        if(k%2 == 0){
            f(n-1 , k/2 , ans);
            ans = 1-ans;
        }
        else{
            f(n-1 , (k+1)/2 , ans);
        }
    }
    int kthGrammar(int n, int k){
        int ans = 0;
        f(n , k , ans);
        return ans ;
    }
};

