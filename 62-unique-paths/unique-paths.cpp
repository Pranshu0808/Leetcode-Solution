class Solution {
public:
    long long uniquePaths(int m, int n) {
        int x = max( m , n);
        int y =  min(m , n);
        long long ct = 1;
        int ctt1 = 1;
        for(int i = (m+n-2); i >= x; --i){
            ct *= i;
            if(ctt1 < y){
                ct = ct/ctt1;
            }
            ctt1++;
        }
        
        for(int i = ctt1; i < y; ++i){
            ct = ct/i;
        }
        
        return ct;
    }
};