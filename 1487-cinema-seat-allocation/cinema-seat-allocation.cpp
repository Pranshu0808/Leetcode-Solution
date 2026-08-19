class Solution {
public:
    int f(int j, vector<bool>& B) {
        int res = 0;
        
        for(int jj = j; jj <= 6; jj += 4) {
            bool ok = true;
            
            for(int k = 0; k < 4; ++k) {
                if(B[jj + k]) {
                    ok = false;
                    break;
                }
            } 

            if(ok)
                res += 1;
        }

        return res;
    }
    
    int maxNumberOfFamilies(int n, vector<vector<int>>& A) {
        int res = 2 * n;
        sort(begin(A), end(A));

        for(int i = 0; i < A.size(); ++i) {
            vector<bool> B(11);
            B[A[i][1]] = 1; 
            
            while(i + 1 < A.size() && A[i][0] == A[i + 1][0])
                B[A[++i][1]] = 1;

            int mx = 0;
            
            for(int j = 2; j <= 6; j += 2) 
                mx = max(mx, f(j, B));
            
            res -= 2 - mx;
        }

        return res;
    }
};