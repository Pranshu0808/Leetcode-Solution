class Solution {
public:
    int maxIncreasingGroups(vector<int>& usageLimits) {
        int n = usageLimits.size();
        sort(usageLimits.begin(), usageLimits.end());
        int lb = 0;
        int ub = n + 1;
        while(lb < ub){
            int mid = (lb + ub) / 2;
            long long delta = 0;
            for(int i = n - 1; i >= 0; --i){
                if (i > n - 1 - mid){
                    delta += usageLimits[i] - (mid - (n - 1 - i));
                }
                delta = min(delta, (long long)0);
                if (i <= n - 1 - mid){
                    delta += usageLimits[i];
                }
            }
            if(delta >= 0){
                lb = mid + 1;
            } else {
                ub = mid;
            }
        }
        return lb - 1;
    }
};