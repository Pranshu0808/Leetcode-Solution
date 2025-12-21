class Solution {
public:
    int findMin(vector<int>& v){
         int n = v.size();
        int lo = 0 , hi = n-1 , ans = INT_MAX;
        while(lo <= hi){
            int mid = (lo+hi)/2;
           
            if(v[lo] <= v[mid]){
                ans = min(ans , v[lo]);
                lo = mid + 1;
            
            }
            else{
                ans = min(ans , v[mid]);
                hi = mid-1;
            }
        }
        return ans;
    }
};