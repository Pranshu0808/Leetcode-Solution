class Solution {
public:
    int distributeCandies(int n, int limit) {
        int cnt = 0;
        int minCh1 = max(0 , n - 2 * limit);
        int maxCh1 = min(n , limit);
        
        for (int i = minCh1; i <= maxCh1; i++) {
            int rem = n - i;
            int minCh2 = max(0 , rem - limit);
            int maxCh2 = min(limit , rem);

            cnt += maxCh2 - minCh2 + 1;
        }
        return cnt;
    }
};