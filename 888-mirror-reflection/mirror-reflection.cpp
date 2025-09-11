class Solution {
public:
    int mirrorReflection(int p, int q) {
        
        int a = p, b = q;
        while (b != 0) {
            int t = a % b;
            a = b;
            b = t;
        }
        int g = a;

        p /= g;  
        q /= g;  

        
        if (p % 2 == 1 && q % 2 == 1) return 1;
        if (p % 2 == 0 && q % 2 == 1) return 2;
        return 0;
    }
};
