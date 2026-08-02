class Solution {
public:
    bool possible(vector<int> arr ,int n , int m , int k , int mid){
        int ct = 0;
        int noOfd = 0;
        for(int i = 0 ; i < n; ++i){
            if(arr[i] <= mid){
                ct++;
            }
            else{
                noOfd += (ct/k);
                ct = 0;
            }
        }
        noOfd += (ct/k);
        return (noOfd >= m);
    }
    int minDays(vector<int>& bloomDay, int m, int k){
        int n = bloomDay.size();
        if(n < (m*1LL*k)){
            return -1;
        }

        int lo = *min_element(bloomDay.begin() , bloomDay.end());
        int hi = *max_element(bloomDay.begin() , bloomDay.end());
        int ans = hi;
        while(lo <= hi){
            int mid = (lo+hi)/2;
            if(possible(bloomDay , n , m , k , mid) == true){
                ans = mid;
                hi = mid-1;
            }
            else{
                lo = mid + 1;
            }
        }
        return ans;
    }
};