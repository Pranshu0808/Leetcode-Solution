class Solution {
public:
    int shipWithinDays(vector<int>& w, int days) {
        int n = w.size();
        int lo = *max_element(w.begin(), w.end());
        int hi = accumulate(w.begin(), w.end(), 0);
        int ans = 0;
        
        while(lo <= hi){
            int mid = (lo + hi) / 2;
            int ct = 1;
            int sum = 0;

            for(int i = 0; i < n; i++){
                if(sum + w[i] > mid){
                    ct++;
                    sum = w[i];
                } else {
                    sum += w[i];
                }
            }

            if(ct <= days){
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
};
