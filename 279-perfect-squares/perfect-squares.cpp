class Solution {
public:
    bool isPerfectSquare(int x) {
        int r = (int) sqrt(x);
        return r * r == x;
    }
    
    int numSquares(int n) {
        if (isPerfectSquare(n)) return 1;
        for (int i = 1; i * i <= n; i++) {
            int j = n - i * i;
            if (isPerfectSquare(j)) return 2;
        }
        int tmp = n;
        while (tmp % 4 == 0) tmp /= 4; 
        if (tmp % 8 == 7) return 4; 
        
        return 3; 
    }
};