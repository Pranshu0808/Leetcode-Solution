class Solution {
public:
    int minSensors(int n, int m, int k){
        int x = (2*k+1);
        n = ceil(n*1.0/(2*k+1));
        m = ceil(m*1.0/(2*k+1));
        return n*m;
    }
};