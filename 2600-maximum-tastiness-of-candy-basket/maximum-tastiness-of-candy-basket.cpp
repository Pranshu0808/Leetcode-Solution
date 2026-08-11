class Solution {
public:

    bool check(vector<int>& price, int k, int d){
        int cnt = 1;
        int last = price[0];

        for(int i = 1; i < price.size(); i++){
            if(price[i] - last >= d){
                cnt++;
                last = price[i];
            }

            if(cnt >= k){
                return true;
            }
        }

        return false;
    }

    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());

        int lo = 0;
        int hi = price.back() - price[0];
        int ans = 0;

        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;

            if(check(price, k, mid)){
                ans = mid;
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }

        return ans;
    }
};