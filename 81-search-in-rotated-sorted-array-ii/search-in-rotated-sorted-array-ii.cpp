class Solution {
public:
    bool search(vector<int>& v, int target) {
        int n = v.size();
        int lo = 0 , hi = n-1;
        while(lo <= hi){
            int mid = (lo+hi)/2;
            if(v[mid] == target){
                return true;
            }
            if(v[lo] == v[mid] && v[mid] == v[hi]){
                lo++;
                hi--;
                continue;
            }
            if(v[lo] <= v[mid]){
                if(v[lo] <= target && target < v[mid]){
                    hi = mid -1;
                }
                else{
                    lo = mid + 1;
                }
            }
            else{
                if(v[mid] < target && target <= v[hi]){
                    lo = mid + 1;
                }
                else{
                    hi = mid - 1;
                }
            }
        }
        return false;
    }
};
 