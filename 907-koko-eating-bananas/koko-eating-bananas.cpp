class Solution {



public:


        long long func(vector<int> piles , int mid){
            int n = piles.size();
            long long tt = 0;
            for(int i = 0; i < n; ++i){
                tt += ceil(piles[i]*1.0/mid);
            }
            return tt;
        }

    int minEatingSpeed(vector<int>& piles, int h){
        
        int lo = 1, hi = *max_element(piles.begin() , piles.end()) , ans = INT_MAX;;
        while(lo <= hi){
            int mid = (lo+ hi )/2;
            long long reqtime = func(piles , mid);
            if(reqtime <= h){
                ans = mid;
                hi = mid-1;
            }
            else{
                lo = mid + 1;
            }
        }
        return lo;

    }
};